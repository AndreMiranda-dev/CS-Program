#
# Thermostat - This is the Python code used to demonstrate
# the functionality of the thermostat that we have prototyped throughout
# the course.
#
# This code works with the test circuit that was built for module 7.
#
# Functionality:
#
# The thermostat has three states: off, heat, cool
#
# The lights will represent the state that the thermostat is in.
#
# If the thermostat is set to off, the lights will both be off.
#
# If the thermostat is set to heat, the Red LED will be fading in
# and out if the current temperature is blow the set temperature;
# otherwise, the Red LED will be on solid.
#
# If the thermostat is set to cool, the Blue LED will be fading in
# and out if the current temperature is above the set temperature;
# otherwise, the Blue LED will be on solid.
#
# One button will cycle through the three states of the thermostat.
#
# One button will raise the setpoint by a degree.
#
# One button will lower the setpoint by a degree.
#
# The LCD display will display the date and time on one line and
# alternate the second line between the current temperature and
# the state of the thermostat along with its set temperature.
#
# The Thermostat will send a status update to the TemperatureServer
# over the serial port every 30 seconds in a comma delimited string
# including the state of the thermostat, the current temperature
# in degrees Fahrenheit, and the setpoint of the thermostat.
#
#------------------------------------------------------------------
# Change History
#------------------------------------------------------------------
# Version   |   Description
#------------------------------------------------------------------
#    1          Initial Development
#    2          Final Project Implementation
#------------------------------------------------------------------

#
# Thermostat - Final Project Implementation
# (Thread-Safe + Humidity on Temp Screen + State Override + AM/PM)
#

from time import sleep, time
from datetime import datetime
from statemachine import StateMachine, State
import board
import adafruit_ahtx0
import digitalio
import adafruit_character_lcd.character_lcd as characterlcd
import serial
from gpiozero import Button, PWMLED
from threading import Thread
from math import floor

DEBUG = True

# ---------------- SENSOR + UART + LED SETUP ----------------

i2c = board.I2C()
thSensor = adafruit_ahtx0.AHTx0(i2c)

ser = serial.Serial(
    port='/dev/ttyS0',
    baudrate=115200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)

redLight = PWMLED(18)
blueLight = PWMLED(23)

# ---------------- LCD DISPLAY CLASS ----------------

class ManagedDisplay:
    def __init__(self):
        self.lcd_rs = digitalio.DigitalInOut(board.D17)
        self.lcd_en = digitalio.DigitalInOut(board.D27)
        self.lcd_d4 = digitalio.DigitalInOut(board.D5)
        self.lcd_d5 = digitalio.DigitalInOut(board.D6)
        self.lcd_d6 = digitalio.DigitalInOut(board.D13)
        self.lcd_d7 = digitalio.DigitalInOut(board.D26)

        self.lcd_columns = 16
        self.lcd_rows = 2

        self.lcd = characterlcd.Character_LCD_Mono(
            self.lcd_rs, self.lcd_en,
            self.lcd_d4, self.lcd_d5,
            self.lcd_d6, self.lcd_d7,
            self.lcd_columns, self.lcd_rows
        )
        self.lcd.clear()

    def updateScreen(self, message):
        self.lcd.clear()
        self.lcd.message = message

    def cleanupDisplay(self):
        self.lcd.clear()
        self.lcd_rs.deinit()
        self.lcd_en.deinit()
        self.lcd_d4.deinit()
        self.lcd_d5.deinit()
        self.lcd_d6.deinit()
        self.lcd_d7.deinit()

screen = ManagedDisplay()

# ---------------- STATE MACHINE ----------------

class TemperatureMachine(StateMachine):
    off = State(initial=True)
    heat = State()
    cool = State()

    setPoint = 72

    # Display counters
    displayCounter = 1
    altCounter = 1

    # Event queue
    pendingEvent = None

    # Button override timer
    lastButtonTime = 0
    overrideActive = False

    cycle = (
        off.to(heat) |
        heat.to(cool) |
        cool.to(off)
    )

    # --- STATE TRANSITIONS ---
    def on_enter_heat(self):
        self.updateLights()
        if DEBUG: print("* Entered HEAT")

    def on_exit_heat(self):
        redLight.off()

    def on_enter_cool(self):
        self.updateLights()
        if DEBUG: print("* Entered COOL")

    def on_exit_cool(self):
        blueLight.off()

    def on_enter_off(self):
        redLight.off()
        blueLight.off()
        if DEBUG: print("* Entered OFF")

    # --- EVENT QUEUE HANDLERS ---
    def queueCycle(self):
        self.pendingEvent = "cycle"

    def queueInc(self):
        self.pendingEvent = "inc"
        self.lastButtonTime = time()
        self.overrideActive = True

    def queueDec(self):
        self.pendingEvent = "dec"
        self.lastButtonTime = time()
        self.overrideActive = True

    # --- LED LOGIC ---
    def updateLights(self):
        temp = floor(self.getFahrenheit())

        redLight.off()
        blueLight.off()

        if self.current_state == self.heat:
            if temp < self.setPoint:
                redLight.pulse(fade_in_time=1, fade_out_time=1)
            else:
                redLight.value = 1

        elif self.current_state == self.cool:
            if temp > self.setPoint:
                blueLight.pulse(fade_in_time=1, fade_out_time=1)
            else:
                blueLight.value = 1

    # --- TEMPERATURE ---
    def getFahrenheit(self):
        t = thSensor.temperature
        return (((9/5) * t) + 32)

    # --- UART OUTPUT ---
    def setupSerialOutput(self):
        state = self.current_state.id
        temp = floor(self.getFahrenheit())
        return f"{state},{temp},{self.setPoint}"

    # --- DISPLAY THREAD ---
    endDisplay = False

    def manageMyDisplay(self):
        while not self.endDisplay:

            now = datetime.now()

            # ---------------- LINE 1: TIME + DATE (unchanged) ----------------
            lcd_line_1 = now.strftime("%m/%d %I:%M%p") + "\n"

            # ---------------- BUTTON OVERRIDE LOGIC ----------------
            if self.overrideActive:
                # If 3 seconds have passed with no button presses → disable override
                if time() - self.lastButtonTime > 3:
                    self.overrideActive = False

            # ---------------- LINE 2: OVERRIDE SCREEN ----------------
            if self.overrideActive:
                lcd_line_2 = f"{self.current_state.id.upper()} {self.setPoint}F"

            # ---------------- NORMAL ALTERNATING DISPLAY ----------------
            else:
                if self.altCounter < 6:
                    temp = floor(self.getFahrenheit())
                    humidity = int(thSensor.relative_humidity)

                    # Build humidity right-aligned (Option 1)
                    hum_str = f"H:{humidity}%"
                    base = f"Temp: {temp}F"
                    spaces = 16 - len(base) - len(hum_str)
                    lcd_line_2 = base + (" " * spaces) + hum_str

                    self.altCounter += 1

                else:
                    lcd_line_2 = f"{self.current_state.id.upper()} {self.setPoint}F"
                    self.altCounter += 1

                    if self.altCounter > 10:
                        self.updateLights()
                        self.altCounter = 1

            # Update LCD
            screen.updateScreen(lcd_line_1 + lcd_line_2)

            # UART every 30 seconds
            if (self.displayCounter % 30) == 0:
                ser.write((self.setupSerialOutput() + "\n").encode())
                self.displayCounter = 1
            else:
                self.displayCounter += 1

            sleep(1)

        screen.cleanupDisplay()

    def run(self):
        Thread(target=self.manageMyDisplay).start()

# ---------------- MAIN PROGRAM ----------------

tsm = TemperatureMachine()
tsm.run()

# Buttons → queue events
greenButton = Button(24)
greenButton.when_pressed = lambda: tsm.queueCycle()

redButton = Button(25)
redButton.when_pressed = lambda: tsm.queueInc()

blueButton = Button(12)
blueButton.when_pressed = lambda: tsm.queueDec()

# MAIN LOOP — processes queued events
try:
    while True:

        if tsm.pendingEvent == "cycle":
            tsm.cycle()
            tsm.updateLights()
            tsm.pendingEvent = None

        elif tsm.pendingEvent == "inc":
            tsm.setPoint += 1
            tsm.updateLights()
            tsm.pendingEvent = None

        elif tsm.pendingEvent == "dec":
            tsm.setPoint -= 1
            tsm.updateLights()
            tsm.pendingEvent = None

        sleep(0.1)

except KeyboardInterrupt:
    print("Cleaning up. Exiting...")
    tsm.endDisplay = True
    sleep(1)

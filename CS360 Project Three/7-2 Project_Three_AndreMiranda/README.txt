Warehouse Inventory Management App
Android • Java • MVVM • Room • WorkManager • SMS Notifications

A complete warehouse inventory management system built for Android using modern architecture patterns.
The app supports user authentication, inventory CRUD operations, SMS notifications, and background low-stock monitoring.

------------------------------------------------------------
TABLE OF CONTENTS
------------------------------------------------------------
• Features
• Architecture
• Screens
• Technologies Used
• Permissions
• Low-Stock Worker
• Project Structure
• Rubric Alignment
• How to Run
• Final Notes

------------------------------------------------------------
FEATURES
------------------------------------------------------------

USER AUTHENTICATION
• Create account
• Log in with stored credentials
• Secure SharedPreferences storage

INVENTORY MANAGEMENT
• Add, edit, delete items
• Grid layout with CardView styling
• Quantity color-coded:
  - Red = Out of stock
  - Orange = Low stock (= 5)
  - Green = Healthy

SMS NOTIFICATIONS (FULLY POLISHED)
• Optional SMS alerts when items reach zero
• Runtime SMS permission request
• Test SMS sending button
• Toggle SMS alerts on/off
• User-configurable phone number with:
  - Auto-formatting (540-555-1234)
  - 10-digit validation
  - Save button disabled until valid
  - Persistent green checkmark when valid
  - Stored in SharedPreferences
• Used by:
  - AddItemActivity
  - EditItemActivity
  - LowStockWorker

BACKGROUND LOW-STOCK WORKER
• Runs every 15 minutes
• Checks for zero-quantity items
• Sends SMS alerts if enabled
• Uses WorkManager (runs even when app is closed)

PERSISTENT LOCAL STORAGE
• Room database
• LiveData auto-updates UI
• ViewModel ensures lifecycle safety

------------------------------------------------------------
ARCHITECTURE (MVVM)
------------------------------------------------------------

MODEL
• InventoryItem
• InventoryDao
• AppDatabase
• InventoryRepository
• NotificationsRepository

VIEWMODEL
• InventoryViewModel
• NotificationsViewModel

VIEW
• MainActivity
• InventoryActivity
• AddItemActivity
• EditItemActivity
• NotificationsActivity

BACKGROUND WORK
• LowStockWorker (WorkManager periodic task)

------------------------------------------------------------
SCREENS
------------------------------------------------------------

MAINACTIVITY
• Login
• Create account

INVENTORYACTIVITY
• Grid of items
• Add item button
• Tap item ? Edit
• Delete item

ADDITEMACTIVITY
• Enter name + quantity
• Save or cancel
• Sends SMS if quantity = 0 and alerts enabled

EDITITEMACTIVITY
• Modify name + quantity
• Save changes
• Delete item
• Sends SMS if quantity becomes 0

NOTIFICATIONSACTIVITY
• Enable/disable SMS alerts
• Request SMS permission
• Test SMS sending
• Enter phone number with auto-formatting + validation
• Green checkmark when valid
• Save button disabled until valid

------------------------------------------------------------
TECHNOLOGIES USED
------------------------------------------------------------
• Java
• Android SDK
• Room Database
• LiveData
• ViewModel
• Repository Pattern
• WorkManager
• ConstraintLayout
• RecyclerView + GridLayoutManager
• SmsManager

------------------------------------------------------------
PERMISSIONS
------------------------------------------------------------
SEND_SMS
• Required only for SMS alerts
• App still functions fully if denied
• Permission status displayed in NotificationsActivity

------------------------------------------------------------
LOW-STOCK WORKER
------------------------------------------------------------
The LowStockWorker:
1. Runs every 15 minutes
2. Queries Room for items with quantity = 0
3. Sends SMS alerts if:
   • SMS alerts are enabled
   • Permission is granted
   • A valid phone number is saved
4. Runs even when the app is closed

------------------------------------------------------------
PROJECT STRUCTURE
------------------------------------------------------------

Project_Two_AndreMiranda/
 +-- java/com/example/project_two_andremiranda/
      • MainActivity.java
      • InventoryActivity.java
      • AddItemActivity.java
      • EditItemActivity.java
      • NotificationsActivity.java
      • InventoryAdapter.java
      • InventoryItem.java
      • InventoryDao.java
      • AppDatabase.java
      • InventoryRepository.java
      • NotificationsRepository.java
      • NotificationsViewModel.java
      • InventoryViewModel.java
      • LowStockWorker.java

 +-- res/layout/
      • activity_main.xml
      • activity_inventory.xml
      • activity_add_item.xml
      • activity_edit_item.xml
      • activity_notifications.xml
      • item_inventory.xml

------------------------------------------------------------
RUBRIC ALIGNMENT
------------------------------------------------------------

USER INTERFACE REQUIREMENTS
• Multiple screens implemented using Activities
• Clean, responsive layouts using ConstraintLayout
• RecyclerView with custom adapter and grid layout
• Input validation on Add/Edit screens
• Modern UI with CardView and color indicators
• Validated, auto-formatted phone number input

DATA STORAGE REQUIREMENTS
• Room database for inventory items
• DAO with insert, update, delete, query
• Repository pattern implemented
• LiveData ensures reactive updates

BACKGROUND PROCESSING
• WorkManager periodic task
• Zero-stock detection logic
• SMS notifications triggered in background

PERMISSIONS & NOTIFICATIONS
• Runtime SMS permission request
• Permission status displayed
• SMS sending via SmsManager
• Optional notification system
• User-configurable phone number with validation

ARCHITECTURE & CODE QUALITY
• MVVM architecture
• ViewModels for all data operations
• Repository abstraction
• Clean, readable, well-commented code
• Full separation of concerns

AUTHENTICATION
• Login + account creation
• SharedPreferences for credential storage

PROFESSIONAL DOCUMENTATION
• README with architecture, features, and rubric mapping
• Clear project structure
• Explanation of SMS system

------------------------------------------------------------
HOW TO RUN
------------------------------------------------------------
1. Clone the project
2. Open in Android Studio
3. Build & run on a real device (SMS requires real hardware)
4. Grant SMS permission if desired
5. Enter a valid phone number in Notifications
6. Add/edit items to test SMS alerts

------------------------------------------------------------
FINAL NOTES
------------------------------------------------------------
This project demonstrates a complete, production-style Android application with modern architecture, background processing, persistent storage, and a polished SMS notification system.
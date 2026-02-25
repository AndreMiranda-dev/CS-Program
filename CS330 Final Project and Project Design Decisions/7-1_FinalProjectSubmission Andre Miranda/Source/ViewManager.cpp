///////////////////////////////////////////////////////////////////////////////
// viewmanager.cpp
// ===============
// manage the viewing of 3D objects within the viewport
//
//  AUTHOR: Brian Battersby - SNHU Instructor / Computer Science
//  Created for CS-330-Computational Graphics and Visualization, Nov. 1st, 2023
///////////////////////////////////////////////////////////////////////////////

#include "ViewManager.h"

// windows API
#include <windows.h>
#include <wingdi.h>

// GLM Math Header inclusions
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// global logging flag definition
bool gEnableLogging = false;

// global light definition default ON
bool gMainLightOn = true;
bool gLightTogglePressed = false;

// global light intensity
float gMainLightIntensity = 1.0f;   // default brightness
bool gIntensityKeyPressed = false;

// declaration of the global variables and defines
namespace
{
	const int WINDOW_WIDTH = 1000;
	const int WINDOW_HEIGHT = 800;
	const char* g_ViewName = "view";
	const char* g_ProjectionName = "projection";

	Camera* g_pCamera = NULL;

	float gLastX = WINDOW_WIDTH / 2.0f;
	float gLastY = WINDOW_HEIGHT / 2.0f;
	bool gFirstMouse = true;

	float gDeltaTime = 0.0f;
	float gLastFrame = 0.0f;

	bool bOrthographicProjection = false;

	bool gPKeyPressed = false;
	bool gOKeyPressed = false;

	bool gLKeyPressed = false;
}

/***********************************************************
 *  ViewManager()
 *
 *  The constructor for the class
 ***********************************************************/
ViewManager::ViewManager(
	ShaderManager* pShaderManager)
{
	// initialize the member variables
	m_pShaderManager = pShaderManager;
	m_pWindow = NULL;

	// create the camera with a good default perspective view
	g_pCamera = new Camera(
		glm::vec3(0.0f, 5.0f, 12.0f),	// position
		glm::vec3(0.0f, 1.0f, 0.0f),	// world up
		-90.0f,							// yaw
		-15.0f);						// pitch (slightly downward)
	g_pCamera->Zoom = 80.0f;
}

/***********************************************************
 *  ~ViewManager()
 *
 *  The destructor for the class
 ***********************************************************/
ViewManager::~ViewManager()
{
	// free up allocated memory
	m_pShaderManager = NULL;
	m_pWindow = NULL;

	if (NULL != g_pCamera)
	{
		delete g_pCamera;
		g_pCamera = NULL;
	}
}

/***********************************************************
 *  CreateDisplayWindow()
 *
 *  This method is used to create the main display window.
 ***********************************************************/
GLFWwindow* ViewManager::CreateDisplayWindow(const char* windowTitle)
{
	GLFWwindow* window = NULL;

	// try to create the displayed OpenGL window
	window = glfwCreateWindow(
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		windowTitle,
		NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(window);

	// initialize bitmap font for HUD text
	InitializeFont();

	// this callback is used to receive mouse moving events
	glfwSetCursorPosCallback(window, &ViewManager::Mouse_Position_Callback);

	// this callback is used to receive scrollwheel spin events
	glfwSetScrollCallback(window, &ViewManager::Mouse_Scroll_Callback);

	// enable blending for supporting transparent rendering
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_pWindow = window;

	// print user instructions
	std::cout << "\n-----------------------------------------\n";
	std::cout << "\n\\/ \\/ \\/  Camera Controls  \\/ \\/ \\/\n";
	std::cout << "W: Move Forward\n";
	std::cout << "S: Move Backward\n";
	std::cout << "A: Move Left\n";
	std::cout << "D: Move Right\n";
	std::cout << "Q: Move Up\n";
	std::cout << "E: Move Down\n";
	std::cout << "Mouse: Look Around\n";
	std::cout << "Scroll: Adjust Movement Speed\n";
	std::cout << "F: Main Light Toggle (returns to default intensity when back on)\n";
	std::cout << "+: Increase Main Light Intenity\n";
	std::cout << "-: Decrease Main Light Intensity\n";
	std::cout << "C: Cinematic Orbit\n";
	std::cout << "P: Perspective View\n";
	std::cout << "O: Orthographic View\n";
	std::cout << "L: Toggle Logging\n";
	std::cout << "ESC: Exit Program\n\n";

	std::cout << "\nLogging: " << (gEnableLogging ? "ON" : "OFF") << " (press L to toggle)\n\n";

	std::cout << "\n/\\ /\\ /\\  Camera Controls  /\\ /\\ /\\\n";
	std::cout << "\n------------------------------------------\n";

	return(window);
}

/***********************************************************
 *  Mouse_Position_Callback()
 *
 *  This method is automatically called from GLFW whenever
 *  the mouse is moved within the active GLFW display window.
 ***********************************************************/
void ViewManager::Mouse_Position_Callback(GLFWwindow* window, double xMousePos, double yMousePos)
{
	// when the first mouse move event is received, record it
	if (gFirstMouse)
	{
		gLastX = (float)xMousePos;
		gLastY = (float)yMousePos;
		gFirstMouse = false;
	}

	// calculate the X offset and Y offset values for moving the 3D camera accordingly
	float xOffset = (float)xMousePos - gLastX;
	float yOffset = gLastY - (float)yMousePos; // reversed since y-coordinates go from bottom to top

	// update last known mouse positions
	gLastX = (float)xMousePos;
	gLastY = (float)yMousePos;

	// move the 3D camera according to the calculated offsets
	if (g_pCamera)
	{
		g_pCamera->ProcessMouseMovement(xOffset, yOffset);

		if (gEnableLogging)
		{
			std::cout << "[Mouse] xOffset=" << xOffset
				<< " yOffset=" << yOffset << std::endl;
		}
	}
}

/***********************************************************
 *  Mouse_Scroll_Callback()
 *
 *  This method is automatically called from GLFW whenever
 *  the scrollwheel spins within the active GLFW display window.
 ***********************************************************/
void ViewManager::Mouse_Scroll_Callback(GLFWwindow* window, double xOffset, double yOffset)
{
	// adjust the movement speed of the camera
	if (g_pCamera)
	{
		float oldSpeed = g_pCamera->MovementSpeed;

		g_pCamera->ProcessMouseScroll((float)yOffset);

		if (gEnableLogging && g_pCamera->MovementSpeed != oldSpeed)
		{
			std::cout << "[Camera] Movement speed: "
				<< g_pCamera->MovementSpeed << std::endl;
		}
	}
}

/***********************************************************
 *  ProcessKeyboardEvents()
 *
 *  This method is called to process any keyboard events
 *  that may be waiting in the event queue.
 ***********************************************************/
void ViewManager::ProcessKeyboardEvents()
{
	// close the window if the escape key has been pressed
	if (glfwGetKey(m_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_pWindow, true);
	}

	// toggle logging with L key
	int lState = glfwGetKey(m_pWindow, GLFW_KEY_L);
	if (lState == GLFW_PRESS && !gLKeyPressed)
	{
		gEnableLogging = !gEnableLogging;

		std::cout << "[Logging] "
			<< (gEnableLogging ? "Enabled" : "Disabled") << std::endl;

		gLKeyPressed = true;
	}
	if (lState == GLFW_RELEASE)
	{
		gLKeyPressed = false;
	}

	// if the camera object is null, then exit this method
	if (NULL == g_pCamera)
	{
		return;
	}

	// process camera zooming in and out
	if (glfwGetKey(m_pWindow, GLFW_KEY_W) == GLFW_PRESS)
	{
		if (gEnableLogging) std::cout << "[Camera] Moving FORWARD\n";
		g_pCamera->ProcessKeyboard(FORWARD, gDeltaTime);
	}
	if (glfwGetKey(m_pWindow, GLFW_KEY_S) == GLFW_PRESS)
	{
		if (gEnableLogging) std::cout << "[Camera] Moving BACKWARD\n";
		g_pCamera->ProcessKeyboard(BACKWARD, gDeltaTime);
	}

	// process camera panning left and right
	if (glfwGetKey(m_pWindow, GLFW_KEY_A) == GLFW_PRESS)
	{
		if (gEnableLogging) std::cout << "[Camera] Moving LEFT\n";
		g_pCamera->ProcessKeyboard(LEFT, gDeltaTime);
	}
	if (glfwGetKey(m_pWindow, GLFW_KEY_D) == GLFW_PRESS)
	{
		if (gEnableLogging) std::cout << "[Camera] Moving RIGHT\n";
		g_pCamera->ProcessKeyboard(RIGHT, gDeltaTime);
	}

	// process camera panning upward and downward
	if (glfwGetKey(m_pWindow, GLFW_KEY_Q) == GLFW_PRESS)
	{
		if (gEnableLogging) std::cout << "[Camera] Moving UP\n";
		g_pCamera->ProcessKeyboard(UP, gDeltaTime);
	}
	if (glfwGetKey(m_pWindow, GLFW_KEY_E) == GLFW_PRESS)
	{
		if (gEnableLogging) std::cout << "[Camera] Moving DOWN\n";
		g_pCamera->ProcessKeyboard(DOWN, gDeltaTime);
	}

	// toggle perspective projection
	int pState = glfwGetKey(m_pWindow, GLFW_KEY_P);
	if (pState == GLFW_PRESS && !gPKeyPressed)
	{
		bOrthographicProjection = false;

		// reset camera to a good perspective view
		if (g_pCamera)
		{
			delete g_pCamera;
		}
		g_pCamera = new Camera(
			glm::vec3(0.0f, 5.0f, 12.0f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			-90.0f,
			-15.0f);
		g_pCamera->Zoom = 80.0f;

		if (gEnableLogging)
		{
			std::cout << "[Projection] Switched to Perspective\n";
		}

		gPKeyPressed = true;
	}
	if (pState == GLFW_RELEASE)
	{
		gPKeyPressed = false;
	}

	// toggle orthographic projection
	int oState = glfwGetKey(m_pWindow, GLFW_KEY_O);
	if (oState == GLFW_PRESS && !gOKeyPressed)
	{
		bOrthographicProjection = true;

		// set camera to a front-facing view so the bottom plane is not visible
		if (g_pCamera)
		{
			delete g_pCamera;
		}
		g_pCamera = new Camera(
			glm::vec3(0.0f, 5.0f, 20.0f),	// further back on Z-axis
			glm::vec3(0.0f, 1.0f, 0.0f),	// world up
			-90.0f,							// yaw: looking along -Z
			0.0f);							// pitch: straight ahead

		if (gEnableLogging)
		{
			std::cout << "[Projection] Switched to Orthographic\n";
		}

		gOKeyPressed = true;
	}
	if (oState == GLFW_RELEASE)
	{
		gOKeyPressed = false;
	}

	// toggle main light off and back on
	int lightState = glfwGetKey(m_pWindow, GLFW_KEY_F);
	if (lightState == GLFW_PRESS && !gLightTogglePressed)
	{
		gMainLightOn = !gMainLightOn;

		// when turning the light back ON, reset intensity to default
		if (gMainLightOn)
		{
			gMainLightIntensity = 1.0f;

			if (gEnableLogging)
			{
				std::cout << "[Lighting] Main light turned ON (intensity reset to 1.0)" << std::endl;
			}
		}
		else
		{
			if (gEnableLogging)
			{
				std::cout << "[Lighting] Main light turned OFF" << std::endl;
			}
		}

		gLightTogglePressed = true;
	}
	if (lightState == GLFW_RELEASE)
	{
		gLightTogglePressed = false;
	}


	// adjust main light intensity with +
	int plusState = glfwGetKey(m_pWindow, GLFW_KEY_EQUAL);
	if (plusState == GLFW_PRESS && !gIntensityKeyPressed)
	{
		gMainLightIntensity += 0.1f;
		if (gMainLightIntensity > 3.0f)
			gMainLightIntensity = 3.0f;

		if (gEnableLogging)
		{
			std::cout << "[Lighting] Main light intensity: "
				<< gMainLightIntensity << std::endl;
		}

		gIntensityKeyPressed = true;
	}
	if (plusState == GLFW_RELEASE)
	{
		gIntensityKeyPressed = false;
	}

	// adjust main light intensity with -
	int minusState = glfwGetKey(m_pWindow, GLFW_KEY_MINUS);
	if (minusState == GLFW_PRESS && !gIntensityKeyPressed)
	{
		gMainLightIntensity -= 0.1f;
		if (gMainLightIntensity < 0.0f)
			gMainLightIntensity = 0.0f;

		if (gEnableLogging)
		{
			std::cout << "[Lighting] Main light intensity: "
				<< gMainLightIntensity << std::endl;
		}

		gIntensityKeyPressed = true;
	}
	if (minusState == GLFW_RELEASE)
	{
		gIntensityKeyPressed = false;
	}


	// Toggle cinematic orbit mode
	static bool cWasPressed = false;

	int cState = glfwGetKey(m_pWindow, GLFW_KEY_C);
	if (cState == GLFW_PRESS && !cWasPressed)
	{
		m_cinematicOrbitEnabled = !m_cinematicOrbitEnabled;

		if (gEnableLogging)
		{
			std::cout << "[Camera] Cinematic orbit "
				<< (m_cinematicOrbitEnabled ? "ENABLED" : "DISABLED") << std::endl;
		}

		cWasPressed = true;
	}
	if (cState == GLFW_RELEASE)
	{
		cWasPressed = false;
	}
}


/***********************************************************
 *  InitializeFont()
 *
 *  This method is used for initialize font for HUD
 ***********************************************************/
void ViewManager::InitializeFont()
{
	HDC hdc = wglGetCurrentDC();
	if (!hdc)
		return;

	// Create a simple Windows font
	HFONT font = CreateFontA(
		-18, 0, 0, 0,
		FW_NORMAL,
		FALSE, FALSE, FALSE,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		FF_DONTCARE | DEFAULT_PITCH,
		"Consolas"
	);

	SelectObject(hdc, font);

	// Generate 256 display lists starting at ID 1000
	m_fontBase = glGenLists(256);
	wglUseFontBitmapsA(hdc, 0, 256, m_fontBase);
}


/***********************************************************
 *  DrawHUDText()
 *
 *  This method is used for draw the HUD text
 ***********************************************************/
void ViewManager::DrawHUDText(float x, float y, const char* text)
{
	if (!m_fontBase || !text)
		return;

	glUseProgram(0);

	// Switch to orthographic projection for 2D overlay
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, 1000, 0, 800, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glColor3f(1.0f, 1.0f, 1.0f); // white text

	glRasterPos2f(x, y);

	while (*text)
	{
		glCallList(m_fontBase + (unsigned char)*text);
		text++;
	}

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}



/***********************************************************
 *  PrepareSceneView()
 *
 *  This method is used for preparing the 3D scene by loading
 *  the shapes, textures in memory to support the 3D scene
 *  rendering
 ***********************************************************/
void ViewManager::PrepareSceneView()
{
	glm::mat4 view;
	glm::mat4 projection;

	// per-frame timing
	float currentFrame = glfwGetTime();
	gDeltaTime = currentFrame - gLastFrame;
	gLastFrame = currentFrame;

	// process any keyboard events that may be waiting in the event queue
	ProcessKeyboardEvents();

	// cinematic orbit camera motion
	if (m_cinematicOrbitEnabled && g_pCamera)
	{
		// advance orbit angle based on time
		m_orbitAngle += m_orbitSpeed * gDeltaTime;

		float radians = glm::radians(m_orbitAngle);

		// compute new camera position on orbit circle
		float camX = m_orbitCenter.x + m_orbitRadius * cos(radians);
		float camZ = m_orbitCenter.z + m_orbitRadius * sin(radians);
		float camY = m_orbitCenter.y + 3.0f; // slight height offset

		g_pCamera->Position = glm::vec3(camX, camY, camZ);

		// always look at the orbit center
		g_pCamera->Front = glm::normalize(m_orbitCenter - g_pCamera->Position);

		// disable mouse look while orbiting
		gFirstMouse = true;
	}

	// get the current view matrix from the camera
	view = g_pCamera->GetViewMatrix();

	// define the current projection matrix
	if (!bOrthographicProjection)
	{
		// perspective projection (3D view)
		projection = glm::perspective(
			glm::radians(g_pCamera->Zoom),
			(GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT,
			0.1f,
			100.0f);
	}
	else
	{
		// orthographic projection (2D-like view)
		float orthoWidth = 10.0f;
		float orthoHeight = 8.0f;

		projection = glm::ortho(
			-orthoWidth, orthoWidth,
			-orthoHeight, orthoHeight,
			0.1f, 100.0f);
	}

	// if the shader manager object is valid
	if (NULL != m_pShaderManager)
	{
		// set the view matrix into the shader for proper rendering
		m_pShaderManager->setMat4Value(g_ViewName, view);
		// set the projection matrix into the shader for proper rendering
		m_pShaderManager->setMat4Value(g_ProjectionName, projection);
		// set the view position of the camera into the shader for proper rendering
		m_pShaderManager->setVec3Value("viewPosition", g_pCamera->Position);
		// toggle light off and back on
		m_pShaderManager->setBoolValue("mainLightEnabled", gMainLightOn);
		// main light intensity
		m_pShaderManager->setFloatValue("mainLightIntensity", gMainLightIntensity);
		// monitor glow pulse
		m_pShaderManager->setFloatValue("uTime", glfwGetTime());
		// steam for coffee
		m_pShaderManager->setFloatValue("steamTime", glfwGetTime());
	}
}
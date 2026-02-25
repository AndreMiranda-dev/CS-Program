///////////////////////////////////////////////////////////////////////////////
// viewmanager.h
// ============
// manage the viewing of 3D objects within the viewport
//
//  AUTHOR: Brian Battersby - SNHU Instructor / Computer Science
//  Created for CS-330-Computational Graphics and Visualization, Nov. 1st, 2023
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <windows.h>
#include <wingdi.h>


#include "ShaderManager.h"
#include "camera.h"

// GLFW library
#include "GLFW/glfw3.h"

// glm for orbit center vector
#include <glm/glm.hpp>

class ViewManager
{
public:
    // constructor
    ViewManager(
        ShaderManager* pShaderManager);
    // destructor
    ~ViewManager();

    // mouse position callback for mouse interaction with the 3D scene
    static void Mouse_Position_Callback(GLFWwindow* window, double xMousePos, double yMousePos);

    // mouse scrollwheel callback for camera movement speed
    static void Mouse_Scroll_Callback(GLFWwindow* window, double xOffset, double yOffset);

    // draw HUD text
    void DrawHUDText(float x, float y, const char* text);
    void InitializeFont();

private:
    // pointer to shader manager object
    ShaderManager* m_pShaderManager;
    // active OpenGL display window
    GLFWwindow* m_pWindow;

    // process keyboard events for interaction with the 3D scene
    void ProcessKeyboardEvents();

    // cinematic orbit camera state
    bool  m_cinematicOrbitEnabled = false;
    float m_orbitAngle = 0.0f;
    float m_orbitSpeed = 20.0f;
    float m_orbitRadius = 15.0f;
    glm::vec3 m_orbitCenter = glm::vec3(0.0f, 2.0f, 0.0f);


    // text based HUD
    unsigned int m_fontBase = 0;

public:
    // create the initial OpenGL display window
    GLFWwindow* CreateDisplayWindow(const char* windowTitle);

    // prepare the conversion from 3D object display to 2D scene display
    void PrepareSceneView();
};
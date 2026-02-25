///////////////////////////////////////////////////////////////////////////////
// shadermanager.h
// ============
// manage the loading and rendering of 3D scenes
//
//  AUTHOR: Brian Battersby - SNHU Instructor / Computer Science
//  Created for CS-330-Computational Graphics and Visualization, Nov. 1st, 2023
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ShaderManager.h"
#include "ShapeMeshes.h"

#include <string>
#include <vector>
#include <memory>

// Centralized texture path constants
namespace TexturePaths {
    constexpr const char* DESKWOOD = "textures/deskwood.jpg";
    constexpr const char* LAPTOPFRAME = "textures/laptopframe.jpg";
    constexpr const char* KEYS = "textures/keys.jpg";
    constexpr const char* MOUSE = "textures/mouse.jpg";
    constexpr const char* PENCIL = "textures/pencil.jpg";
    constexpr const char* BOOK1 = "textures/book1.jpg";
    constexpr const char* BOOK2 = "textures/book2.jpg";
    constexpr const char* BOOK3 = "textures/book3.jpg";
    constexpr const char* SCREENS = "textures/screens.jpg";
    constexpr const char* MUG = "textures/mug.jpg";
    constexpr const char* CUP = "textures/cup.jpg";
    constexpr const char* SOCCERBALL = "textures/soccerball.jpg";
}

// Centralized texture tag constants
namespace TextureTags {
    constexpr const char* DESKWOOD = "deskwood";
    constexpr const char* LAPTOPFRAME = "laptopframe";
    constexpr const char* KEYS = "keys";
    constexpr const char* MOUSE = "mouse";
    constexpr const char* PENCIL = "pencil";
    constexpr const char* BOOK1 = "book1";
    constexpr const char* BOOK2 = "book2";
    constexpr const char* BOOK3 = "book3";
    constexpr const char* SCREENS = "screens";
    constexpr const char* MUG = "mug";
    constexpr const char* CUP = "cup";
    constexpr const char* SOCCERBALL = "soccerball";
}


/***********************************************************
 *  SceneManager
 *
 *  This class contains the code for preparing and rendering
 *  3D scenes, including the shader settings.
 ***********************************************************/

 // forward declaration for encapsulated scene objects
class SceneObject;

class SceneManager
{
public:
    // constructor
    SceneManager(ShaderManager* pShaderManager);
    // destructor
    ~SceneManager();

    struct TEXTURE_INFO
    {
        std::string tag = "";
        uint32_t ID = 0;
    };

    struct OBJECT_MATERIAL
    {
        float ambientStrength = 0.2f;
        glm::vec3 ambientColor = glm::vec3(0.2f);
        glm::vec3 diffuseColor = glm::vec3(0.5f);
        glm::vec3 specularColor = glm::vec3(0.1f);
        float shininess = 16.0f;
        std::string tag = "";
    };

private:
    // pointer to shader manager object
    ShaderManager* m_pShaderManager;
    // pointer to basic shapes object
    ShapeMeshes* m_basicMeshes;
    // total number of loaded textures
    int m_loadedTextures;
    // loaded textures info
    TEXTURE_INFO m_textureIDs[16];
    // defined object materials
    std::vector<OBJECT_MATERIAL> m_objectMaterials;

    // encapsulated scene objects
    std::vector<std::unique_ptr<SceneObject>> m_sceneObjects;

    // load texture images and convert to OpenGL texture data
    bool CreateGLTexture(const char* filename, std::string tag);
    // bind loaded OpenGL textures to slots in memory
    void BindGLTextures();
    // free the loaded OpenGL textures
    void DestroyGLTextures();
    // find a loaded texture by tag
    int FindTextureID(std::string tag);
    int FindTextureSlot(std::string tag);
    // find a defined material by tag
    bool FindMaterial(std::string tag, OBJECT_MATERIAL& material);

public:

    // set the transformation values into the transform buffer
    void SetTransformations(
        glm::vec3 scaleXYZ,
        float XrotationDegrees,
        float YrotationDegrees,
        float ZrotationDegrees,
        glm::vec3 positionXYZ);

    // set the color values into the shader
    void SetShaderColor(
        float redColorValue,
        float greenColorValue,
        float blueColorValue,
        float alphaValue);

    // set the texture data into the shader
    void SetShaderTexture(
        std::string textureTag);

    // set two textures and a blend factor into the shader
    void SetShaderTextureBlend(std::string textureTag1, std::string textureTag2, float mixValue);

    // set the UV scale for the texture mapping
    void SetTextureUVScale(
        float u, float v);

    // set the object material into the shader
    void SetShaderMaterial(
        std::string materialTag);

    // set a boolean uniform in the shader
    void SetBoolValue(const std::string& name, bool value);

    // set emissive glow strength
    void SetEmissiveStrength(float strength);

    // set shadow color
    void SetShadowColor(const glm::vec4& color);

public:

    // The following methods are for the students to 
    // customize for their own 3D scene
    void PrepareScene();
    void RenderScene();

};
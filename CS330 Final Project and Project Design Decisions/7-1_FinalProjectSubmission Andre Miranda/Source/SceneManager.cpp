///////////////////////////////////////////////////////////////////////////////
// shadermanager.cpp
// ============
// manage the loading and rendering of 3D scenes
//
//  AUTHOR: Brian Battersby - SNHU Instructor / Computer Science
//  Created for CS-330-Computational Graphics and Visualization, Nov. 1st, 2023
///////////////////////////////////////////////////////////////////////////////

#include "SceneManager.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif

#include <glm/gtx/transform.hpp>
#include <array>

// external globals
extern bool gMainLightOn;
extern float gMainLightIntensity;

// Include encapsulated scene object classes
#include "SceneObject.h"
#include "DeskObject.h"
#include "LaptopObject.h"
#include "MonitorsObject.h"
#include "BooksObject.h"
#include "KeyboardObject.h"
#include "PencilCupObject.h"
#include "MouseObject.h"
#include "MugObject.h"
#include "SoccerBallObject.h"

// Declaration of global variables
namespace
{
    const char* g_ModelName = "model";
    const char* g_ColorValueName = "objectColor";
    const char* g_TextureValueName = "objectTexture";
    const char* g_UseTextureName = "bUseTexture";
    const char* g_UseLightingName = "bUseLighting";

    constexpr int TOTAL_LIGHTS = 5;

    struct LightData
    {
        glm::vec3 position;
        glm::vec3 ambientColor;
        glm::vec3 diffuseColor;
        glm::vec3 specularColor;
        float     focalStrength;
        float     specularIntensity;
    };

    // High-level semantic constants
    const glm::vec3 SUN_DIRECTION = glm::normalize(glm::vec3(-1.0f, -0.5f, -0.3f));
    const float     SUN_DISTANCE = 1000.0f;

    const glm::vec3 MONITOR_GLOW_COLOR = glm::vec3(0.20f, 0.28f, 0.45f);
    const glm::vec3 LAPTOP_GLOW_COLOR = glm::vec3(0.18f, 0.22f, 0.32f);

    // Predefined light set
    const std::array<LightData, TOTAL_LIGHTS> SCENE_LIGHTS = {
        // 0 — Overhead warm room light
        LightData{
            glm::vec3(0.0f, 8.0f, 0.0f),
            glm::vec3(0.32f, 0.28f, 0.24f),
            glm::vec3(0.75f, 0.65f, 0.55f),
            glm::vec3(0.25f, 0.22f, 0.20f),
            16.0f,
            0.12f
        },
        // 1 — Warm sunlight
        LightData{
            SUN_DIRECTION * SUN_DISTANCE,
            glm::vec3(0.40f, 0.42f, 0.48f),
            glm::vec3(0.55f, 0.60f, 0.70f),
            glm::vec3(0.45f, 0.50f, 0.60f),
            4.0f,
            0.06f
        },
        // 2 — Left monitor glow
        LightData{
            glm::vec3(-6.0f, 3.0f, -0.3f),
            MONITOR_GLOW_COLOR,
            MONITOR_GLOW_COLOR,
            MONITOR_GLOW_COLOR,
            8.0f,
            0.06f
        },
        // 3 — Right monitor glow
        LightData{
            glm::vec3(6.0f, 3.0f, -0.3f),
            MONITOR_GLOW_COLOR,
            MONITOR_GLOW_COLOR,
            MONITOR_GLOW_COLOR,
            8.0f,
            0.06f
        },
        // 4 — Laptop screen glow
        LightData{
            glm::vec3(0.0f, 1.2f, -2.1f),
            LAPTOP_GLOW_COLOR,
            LAPTOP_GLOW_COLOR,
            LAPTOP_GLOW_COLOR,
            8.0f,
            0.05f
        }
    };
}

/***********************************************************
 *  SceneManager()
 *
 *  The constructor for the class
 ***********************************************************/
SceneManager::SceneManager(ShaderManager* pShaderManager)
{
    m_pShaderManager = pShaderManager;
    m_basicMeshes = new ShapeMeshes();
    m_loadedTextures = 0;
}

/***********************************************************
 *  ~SceneManager()
 *
 *  The destructor for the class
 ***********************************************************/
SceneManager::~SceneManager()
{
    m_pShaderManager = NULL;
    delete m_basicMeshes;
    m_basicMeshes = NULL;
}

/***********************************************************
 *  CreateGLTexture()
 *
 *  This method is used for loading textures from image files,
 *  configuring the texture mapping parameters in OpenGL,
 *  generating the mipmaps, and loading the read texture into
 *  the next available texture slot in memory.
 ***********************************************************/
bool SceneManager::CreateGLTexture(const char* filename, std::string tag)
{
    int width = 0;
    int height = 0;
    int colorChannels = 0;
    GLuint textureID = 0;

    // indicate to always flip images vertically when loaded
    stbi_set_flip_vertically_on_load(true);

    // try to parse the image data from the specified image file
    unsigned char* image = stbi_load(
        filename,
        &width,
        &height,
        &colorChannels,
        0);

    // if the image was successfully read from the image file
    if (image)
    {
        std::cout << "Successfully loaded image:" << filename << ", width:" << width << ", height:" << height << ", channels:" << colorChannels << std::endl;

        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // if the loaded image is in RGB format
        if (colorChannels == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        // if the loaded image is in RGBA format - it supports transparency
        else if (colorChannels == 4)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        else
        {
            std::cout << "Not implemented to handle image with " << colorChannels << " channels" << std::endl;
            return false;
        }

        // generate the texture mipmaps for mapping textures to lower resolutions
        glGenerateMipmap(GL_TEXTURE_2D);

        // free the image data from local memory
        stbi_image_free(image);
        glBindTexture(GL_TEXTURE_2D, 0); // Unbind the texture

        // register the loaded texture and associate it with the special tag string
        m_textureIDs[m_loadedTextures].ID = textureID;
        m_textureIDs[m_loadedTextures].tag = tag;
        m_loadedTextures++;

        return true;
    }

    std::cout << "Could not load image:" << filename << std::endl;

    // Error loading the image
    return false;
}

/***********************************************************
 *  BindGLTextures()
 *
 *  This method is used for binding the loaded textures to
 *  OpenGL texture memory slots.  There are up to 16 slots.
 ***********************************************************/
void SceneManager::BindGLTextures()
{
    for (int i = 0; i < m_loadedTextures; i++)
    {
        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, m_textureIDs[i].ID);
    }
}

/***********************************************************
 *  DestroyGLTextures()
 *
 *  This method is used for freeing the memory in all the
 *  used texture memory slots.
 ***********************************************************/
void SceneManager::DestroyGLTextures()
{
    for (int i = 0; i < m_loadedTextures; i++)
    {
        glDeleteTextures(1, &m_textureIDs[i].ID);
    }
}

/***********************************************************
 *  FindTextureID()
 *
 *  This method is used for getting an ID for the previously
 *  loaded texture bitmap associated with the passed in tag.
 ***********************************************************/
int SceneManager::FindTextureID(std::string tag)
{
    int textureID = -1;
    int index = 0;
    bool bFound = false;

    while ((index < m_loadedTextures) && (bFound == false))
    {
        if (m_textureIDs[index].tag.compare(tag) == 0)
        {
            textureID = m_textureIDs[index].ID;
            bFound = true;
        }
        else
            index++;
    }

    return(textureID);
}

/***********************************************************
 *  FindTextureSlot()
 *
 *  This method is used for getting a slot index for the previously
 *  loaded texture bitmap associated with the passed in tag.
 ***********************************************************/
int SceneManager::FindTextureSlot(std::string tag)
{
    int textureSlot = -1;
    int index = 0;
    bool bFound = false;

    while ((index < m_loadedTextures) && (bFound == false))
    {
        if (m_textureIDs[index].tag.compare(tag) == 0)
        {
            textureSlot = index;
            bFound = true;
        }
        else
            index++;
    }

    return(textureSlot);
}

/***********************************************************
 *  FindMaterial()
 *
 *  This method is used for getting a material from the previously
 *  defined materials list that is associated with the passed in tag.
 ***********************************************************/
bool SceneManager::FindMaterial(std::string tag, OBJECT_MATERIAL& material)
{
    if (m_objectMaterials.size() == 0)
    {
        return(false);
    }

    int index = 0;
    bool bFound = false;
    while ((index < m_objectMaterials.size()) && (bFound == false))
    {
        if (m_objectMaterials[index].tag.compare(tag) == 0)
        {
            bFound = true;
            material.ambientColor = m_objectMaterials[index].ambientColor;
            material.ambientStrength = m_objectMaterials[index].ambientStrength;
            material.diffuseColor = m_objectMaterials[index].diffuseColor;
            material.specularColor = m_objectMaterials[index].specularColor;
            material.shininess = m_objectMaterials[index].shininess;
        }
        else
        {
            index++;
        }
    }

    return(true);
}

/***********************************************************
 *  SetTransformations()
 *
 *  This method is used for setting the transform buffer
 *  using the passed in transformation values.
 ***********************************************************/
void SceneManager::SetTransformations(
    glm::vec3 scaleXYZ,
    float XrotationDegrees,
    float YrotationDegrees,
    float ZrotationDegrees,
    glm::vec3 positionXYZ)
{
    // variables for this method
    glm::mat4 modelView;
    glm::mat4 scale;
    glm::mat4 rotationX;
    glm::mat4 rotationY;
    glm::mat4 rotationZ;
    glm::mat4 translation;

    // set the scale value in the transform buffer
    scale = glm::scale(scaleXYZ);
    // set the rotation values in the transform buffer
    rotationX = glm::rotate(glm::radians(XrotationDegrees), glm::vec3(1.0f, 0.0f, 0.0f));
    rotationY = glm::rotate(glm::radians(YrotationDegrees), glm::vec3(0.0f, 1.0f, 0.0f));
    rotationZ = glm::rotate(glm::radians(ZrotationDegrees), glm::vec3(0.0f, 0.0f, 1.0f));
    // set the translation value in the transform buffer
    translation = glm::translate(positionXYZ);

    modelView = translation * rotationX * rotationY * rotationZ * scale;

    if (NULL != m_pShaderManager)
    {
        m_pShaderManager->setMat4Value(g_ModelName, modelView);
    }
}

/***********************************************************
 *  SetShaderColor()
 *
 *  This method is used for setting the passed in color
 *  into the shader for the next draw command
 ***********************************************************/
void SceneManager::SetShaderColor(
    float redColorValue,
    float greenColorValue,
    float blueColorValue,
    float alphaValue)
{
    // variables for this method
    glm::vec4 currentColor;

    currentColor.r = redColorValue;
    currentColor.g = greenColorValue;
    currentColor.b = blueColorValue;
    currentColor.a = alphaValue;

    if (NULL != m_pShaderManager)
    {
        m_pShaderManager->setIntValue(g_UseTextureName, false);
        m_pShaderManager->setVec4Value(g_ColorValueName, currentColor);
    }
}

/***********************************************************
 *  SetShaderTexture()
 *
 *  This method is used for setting the texture data
 *  associated with the passed in ID into the shader.
 ***********************************************************/
void SceneManager::SetShaderTexture(
    std::string textureTag)
{
    if (NULL != m_pShaderManager)
    {
        m_pShaderManager->setIntValue(g_UseTextureName, true);

        int textureID = -1;
        textureID = FindTextureSlot(textureTag);
        m_pShaderManager->setSampler2DValue(g_TextureValueName, textureID);
    }
}


/***********************************************************
 *  SetShaderTextureBlend()
 *
 *  This method is used for setting the texture blend data
 *  associated with the passed in ID into the shader.
 ***********************************************************/
void SceneManager::SetShaderTextureBlend(std::string textureTag1, std::string textureTag2, float mixValue)
{
    if (m_pShaderManager)
    {
        // Enable texture usage
        m_pShaderManager->setIntValue(g_UseTextureName, true);

        // objectTexture
        int slot1 = FindTextureSlot(textureTag1);
        m_pShaderManager->setSampler2DValue("objectTexture", slot1);

        // Texture2
        int slot2 = FindTextureSlot(textureTag2);
        m_pShaderManager->setSampler2DValue("texture2", slot2);

        // Blend factor
        m_pShaderManager->setFloatValue("textureMix", mixValue);
    }
}



/***********************************************************
 *  SetTextureUVScale()
 *
 *  This method is used for setting the texture UV scale
 *  values into the shader.
 ***********************************************************/
void SceneManager::SetTextureUVScale(float u, float v)
{
    if (NULL != m_pShaderManager)
    {
        m_pShaderManager->setVec2Value("UVscale", glm::vec2(u, v));
    }
}

/***********************************************************
 *  SetShaderMaterial()
 *
 *  This method is used for passing the material values
 *  into the shader.
 ***********************************************************/
void SceneManager::SetShaderMaterial(
    std::string materialTag)
{
    if (m_objectMaterials.size() > 0)
    {
        OBJECT_MATERIAL material;
        bool bReturn = false;

        bReturn = FindMaterial(materialTag, material);
        if (bReturn == true)
        {
            m_pShaderManager->setVec3Value("material.ambientColor", material.ambientColor);
            m_pShaderManager->setFloatValue("material.ambientStrength", material.ambientStrength);
            m_pShaderManager->setVec3Value("material.diffuseColor", material.diffuseColor);
            m_pShaderManager->setVec3Value("material.specularColor", material.specularColor);
            m_pShaderManager->setFloatValue("material.shininess", material.shininess);
        }
    }
}

/***********************************************************
 *  SetBoolValuel()
 *
 *  This method is used for passing a boolean uniform
 * into the shader program.
 ***********************************************************/
void SceneManager::SetBoolValue(const std::string& name, bool value)
{
    if (m_pShaderManager)
    {
        m_pShaderManager->setBoolValue(name, value);
    }
}

/**************************************************************/
/*** STUDENTS CAN MODIFY the code in the methods BELOW for  ***/
/*** preparing and rendering their own 3D replicated scenes.***/
/*** Please refer to the code in the OpenGL sample project  ***/
/*** for assistance.                                        ***/
/**************************************************************/


/***********************************************************
 *  PrepareScene()
 *
 *  This method is used for preparing the 3D scene by loading
 *  the shapes, textures in memory to support the 3D scene
 *  rendering
 ***********************************************************/
void SceneManager::PrepareScene()
{
    if (m_basicMeshes == nullptr)
    {
        return;
    }

    // Load all meshes needed for the scene
    m_basicMeshes->LoadPlaneMesh();
    m_basicMeshes->LoadBoxMesh();
    m_basicMeshes->LoadCylinderMesh();
    m_basicMeshes->LoadConeMesh();
    m_basicMeshes->LoadTaperedCylinderMesh();
    m_basicMeshes->LoadTorusMesh();
    m_basicMeshes->LoadSphereMesh();

    /***********************************************************
    * TEXTURE LOADING
    ***********************************************************/

    CreateGLTexture(TexturePaths::DESKWOOD, TextureTags::DESKWOOD);
    CreateGLTexture(TexturePaths::LAPTOPFRAME, TextureTags::LAPTOPFRAME);
    CreateGLTexture(TexturePaths::KEYS, TextureTags::KEYS);
    CreateGLTexture(TexturePaths::MOUSE, TextureTags::MOUSE);
    CreateGLTexture(TexturePaths::PENCIL, TextureTags::PENCIL);
    CreateGLTexture(TexturePaths::BOOK1, TextureTags::BOOK1);
    CreateGLTexture(TexturePaths::BOOK2, TextureTags::BOOK2);
    CreateGLTexture(TexturePaths::BOOK3, TextureTags::BOOK3);
    CreateGLTexture(TexturePaths::SCREENS, TextureTags::SCREENS);
    CreateGLTexture(TexturePaths::MUG, TextureTags::MUG);
    CreateGLTexture(TexturePaths::CUP, TextureTags::CUP);
    CreateGLTexture(TexturePaths::SOCCERBALL, TextureTags::SOCCERBALL);

    /***********************************************************
    * Create encapsulated scene objects
    ***********************************************************/
    m_sceneObjects.clear();
    m_sceneObjects.emplace_back(std::make_unique<DeskObject>());
    m_sceneObjects.emplace_back(std::make_unique<LaptopObject>());
    m_sceneObjects.emplace_back(std::make_unique<MonitorsObject>());
    m_sceneObjects.emplace_back(std::make_unique<BooksObject>());
    m_sceneObjects.emplace_back(std::make_unique<KeyboardObject>());
    m_sceneObjects.emplace_back(std::make_unique<MouseObject>());
    m_sceneObjects.emplace_back(std::make_unique<PencilCupObject>());
    m_sceneObjects.emplace_back(std::make_unique<MugObject>());
    m_sceneObjects.emplace_back(std::make_unique<SoccerBallObject>());

    /***********************************************************
    * Create desk material
    ***********************************************************/
    SceneManager::OBJECT_MATERIAL deskMat{};
    deskMat.tag = "desk";
    deskMat.ambientStrength = 0.3f;
    deskMat.ambientColor = glm::vec3(0.4f, 0.25f, 0.15f);
    deskMat.diffuseColor = glm::vec3(0.75f, 0.50f, 0.30f);
    deskMat.specularColor = glm::vec3(0.9f, 0.9f, 0.9f);
    deskMat.shininess = 32.0f;

    m_objectMaterials.push_back(deskMat);


    /***********************************************************
    * Create flat material
    ***********************************************************/
    SceneManager::OBJECT_MATERIAL flatMat{};
    flatMat.tag = "flatTexture";
    flatMat.ambientStrength = 0.85f;
    flatMat.ambientColor = glm::vec3(1.0f);
    flatMat.diffuseColor = glm::vec3(0.2f);
    flatMat.specularColor = glm::vec3(0.0f);
    flatMat.shininess = 1.0f;

    m_objectMaterials.push_back(flatMat);
}

/***********************************************************
* Emissive
***********************************************************/
void SceneManager::SetEmissiveStrength(float strength)
{
    if (m_pShaderManager)
        m_pShaderManager->setFloatValue("emissiveStrength", strength);
}

/***********************************************************
* Shadow
***********************************************************/
void SceneManager::SetShadowColor(const glm::vec4& color)
{
    m_pShaderManager->setVec4Value("shadowColor", color);
}

/***********************************************************
 *  RenderScene()
 *
 *  This method is used for rendering the 3D scene by
 *  transforming and drawing the basic 3D shapes
 ***********************************************************/
void SceneManager::RenderScene()
{
    // Loop for uploading all lights
    for (int i = 0; i < TOTAL_LIGHTS; ++i)
    {
        const LightData& light = SCENE_LIGHTS[i];
        std::string base = "lightSources[" + std::to_string(i) + "].";

        // Main light off/on and intensity
        if (i == 0)
        {
            m_pShaderManager->setBoolValue(base + "enabled", gMainLightOn);
            m_pShaderManager->setFloatValue(base + "intensity", gMainLightIntensity);
        }
        else
        {
            m_pShaderManager->setBoolValue(base + "enabled", true);
            m_pShaderManager->setFloatValue(base + "intensity", 1.0f);
        }

        // Upload light data
        m_pShaderManager->setVec3Value(base + "position", light.position);
        m_pShaderManager->setVec3Value(base + "ambientColor", light.ambientColor);
        m_pShaderManager->setVec3Value(base + "diffuseColor", light.diffuseColor);
        m_pShaderManager->setVec3Value(base + "specularColor", light.specularColor);
        m_pShaderManager->setFloatValue(base + "focalStrength", light.focalStrength);
        m_pShaderManager->setFloatValue(base + "specularIntensity", light.specularIntensity);
    }

    // Enable lighting in shader
    m_pShaderManager->setBoolValue("bUseLighting", true);

    // Emissive strength
    m_pShaderManager->setFloatValue("emissiveStrength", 0.0f);



    // Render objects
    if (m_basicMeshes == nullptr)
        return;

    // Bind all loaded textures
    BindGLTextures();

    // Render each encapsulated object
    for (auto& object : m_sceneObjects)
    {
        if (object)
            object->Render(*this, *m_basicMeshes);
    }
}
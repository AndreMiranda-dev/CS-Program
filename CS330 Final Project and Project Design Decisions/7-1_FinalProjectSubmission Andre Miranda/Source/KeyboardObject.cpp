///////////////////////////////////////////////////////////////////////////////
// keyboardobject.cpp
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#include "KeyboardObject.h"

void KeyboardObject::Render(SceneManager& scene, ShapeMeshes& meshes)
{
    // Shadow under keyboard
    scene.SetTransformations(
        { 3.4f, 0.02f, 1.4f },
        0.0f, 0.0f, 0.0f,
        { -0.3f, -0.001f, 2.3f }
    );

    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderColor(0.0f, 0.0f, 0.0f, 0.15f);

    meshes.DrawTaperedCylinderMesh();

    // Reset color
    scene.SetShaderColor(1.0f, 1.0f, 1.0f, 1.0f);


    RenderBase(scene, meshes);
    RenderKeys(scene, meshes);
}

void KeyboardObject::RenderBase(SceneManager& scene, ShapeMeshes& meshes)
{
    scene.SetTransformations({ 3.0f, 0.15f, 1.0f }, 0, 0, 0, { 0.0f, 0.0f, 2.0f });
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::LAPTOPFRAME, TextureTags::MOUSE, 0.20f);
    meshes.DrawBoxMesh();
}

void KeyboardObject::RenderKeys(SceneManager& scene, ShapeMeshes& meshes)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 12; col++)
        {
            glm::vec3 scaleXYZ(0.18f, 0.05f, 0.18f);
            float xPos = -1.0f + (col * 0.18f);
            float zPos = 1.6f + (row * 0.18f);
            glm::vec3 pos(xPos, 0.10f, zPos);

            scene.SetTransformations(scaleXYZ, 0, 0, 0, pos);
            scene.SetShaderMaterial("flatTexture");
            scene.SetShaderTextureBlend(TextureTags::KEYS, TextureTags::MOUSE, 0.10f);
            meshes.DrawBoxMesh();
        }
    }
}
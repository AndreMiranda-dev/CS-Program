///////////////////////////////////////////////////////////////////////////////
// laptopobject.cpp
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#include "LaptopObject.h"

void LaptopObject::Render(SceneManager& scene, ShapeMeshes& meshes)
{
    // Shadow under laptop
    scene.SetTransformations(
        { 2.6f, 0.03f, 1.6f },
        0.0f, 0.0f, 0.0f,
        { -0.4f, 0.015f, -0.4f }
    );

    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderColor(0.0f, 0.0f, 0.0f, 0.15f);

    meshes.DrawTaperedCylinderMesh();

    // Reset color
    scene.SetShaderColor(1.0f, 1.0f, 1.0f, 1.0f);


    // Base
    const glm::vec3 BASE_SCALE(3.5f, 0.12f, 2.2f);
    const glm::vec3 BASE_POS(0.0f, 0.0f, -1.0f);

    scene.SetTransformations(BASE_SCALE, 0.0f, 0.0f, 0.0f, BASE_POS);
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::LAPTOPFRAME, TextureTags::MOUSE, 0.20f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawBoxMesh();

    // Keys, trackpad, power button on laptop base
    RenderKeys(scene, meshes);
    RenderTrackpad(scene, meshes);
    RenderPowerButton(scene, meshes);

    // Screen frame
    const glm::vec3 FRAME_SCALE(3.5f, 2.0f, 0.10f);
    const glm::vec3 FRAME_POS(0.0f, 1.12f, -2.05f);

    scene.SetTransformations(FRAME_SCALE, 0.0f, 0.0f, 0.0f, FRAME_POS);
    scene.SetShaderTextureBlend(TextureTags::LAPTOPFRAME, TextureTags::MOUSE, 0.20f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawBoxMesh();

    // Thin front screen panel
    const glm::vec3 PANEL_SCALE(3.48f, 1.98f, 0.02f);
    const glm::vec3 PANEL_POS(0.0f, 1.12f, -1.99f);

    scene.SetTransformations(PANEL_SCALE, 0.0f, 0.0f, 0.0f, PANEL_POS);

    // Glow on
    scene.SetEmissiveStrength(0.25f);

    scene.SetShaderTextureBlend(TextureTags::SCREENS, TextureTags::BOOK3, 0.05f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawBoxMesh();

    // Glow off
    scene.SetEmissiveStrength(0.0f);


}

void LaptopObject::RenderKeys(SceneManager& scene, ShapeMeshes& meshes)
{
    // Laptop key layout
    const int ROWS = 4;
    const int COLS = 10;

    const float KEY_SCALE = 0.15f;
    const float KEY_HEIGHT = 0.05f;
    const float SPACING = KEY_SCALE * 1.2f;

    // Laptop base center
    const float LAPTOP_CENTER_X = 0.0f;
    const float LAPTOP_CENTER_Z = -1.0f;

    // Keys sit on top of laptop base
    const float BASE_TOP_Y = 0.12f;
    const float KEY_Y = BASE_TOP_Y + KEY_HEIGHT;

    // Total extents of key grid
    const float TOTAL_WIDTH = (COLS - 1) * SPACING;
    const float TOTAL_DEPTH = (ROWS - 1) * SPACING;

    // Start positions so grid is centered on laptop base
    const float START_X = LAPTOP_CENTER_X - (TOTAL_WIDTH * 0.5f);
    const float START_Z = LAPTOP_CENTER_Z - (TOTAL_DEPTH * 0.5f);

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            glm::vec3 scaleXYZ(KEY_SCALE, KEY_HEIGHT, KEY_SCALE);

            float xPos = START_X + (col * SPACING);
            float zPos = START_Z + (row * SPACING);

            glm::vec3 pos(xPos, KEY_Y, zPos);

            scene.SetTransformations(scaleXYZ, 0, 0, 0, pos);
            scene.SetShaderMaterial("flatTexture");
            scene.SetShaderTextureBlend(TextureTags::KEYS, TextureTags::MOUSE, 0.10f);
            meshes.DrawBoxMesh();
        }
    }
}

void LaptopObject::RenderTrackpad(SceneManager& scene, ShapeMeshes& meshes)
{
    // Trackpad centered below key area
    const float TRACKPAD_WIDTH = 1.4f;
    const float TRACKPAD_DEPTH = 0.8f;
    const float TRACKPAD_HEIGHT = 0.03f;

    const float LAPTOP_CENTER_X = 0.0f;
    const float LAPTOP_CENTER_Z = -1.0f;

    const float BASE_TOP_Y = 0.12f;
    const float TRACKPAD_Y = BASE_TOP_Y + TRACKPAD_HEIGHT * 0.5f;

    const float TRACKPAD_Z = LAPTOP_CENTER_Z + 0.6f;

    glm::vec3 scaleXYZ(TRACKPAD_WIDTH, TRACKPAD_HEIGHT, TRACKPAD_DEPTH);
    glm::vec3 pos(LAPTOP_CENTER_X, TRACKPAD_Y, TRACKPAD_Z);

    scene.SetTransformations(scaleXYZ, 0, 0, 0, pos);
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::LAPTOPFRAME, TextureTags::MOUSE, 0.05f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawBoxMesh();
}

void LaptopObject::RenderPowerButton(SceneManager& scene, ShapeMeshes& meshes)
{
    // Power Button
    const float BUTTON_SCALE = 0.18f;
    const float BUTTON_HEIGHT = 0.05f;

    const float LAPTOP_CENTER_X = 0.0f;
    const float LAPTOP_CENTER_Z = -1.0f;

    const float BASE_TOP_Y = 0.12f;
    const float BUTTON_Y = BASE_TOP_Y + BUTTON_HEIGHT;

    const float OFFSET_X = 1.4f;
    const float OFFSET_Z = -0.6f;

    glm::vec3 scaleXYZ(BUTTON_SCALE, BUTTON_HEIGHT, BUTTON_SCALE);
    glm::vec3 pos(LAPTOP_CENTER_X + OFFSET_X, BUTTON_Y, LAPTOP_CENTER_Z + OFFSET_Z);

    scene.SetTransformations(scaleXYZ, 0, 0, 0, pos);
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::KEYS, TextureTags::MOUSE, 0.10f);
    meshes.DrawBoxMesh();
}
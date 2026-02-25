///////////////////////////////////////////////////////////////////////////////
// monitorsobject.cpp
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#include "MonitorsObject.h"

void MonitorsObject::Render(SceneManager& scene, ShapeMeshes& meshes)
{
    RenderLeftMonitor(scene, meshes);
    RenderRightMonitor(scene, meshes);
}

void MonitorsObject::RenderLeftMonitor(SceneManager& scene, ShapeMeshes& meshes)
{
    // Shadow under monitor
    scene.SetTransformations(
        { 3.0f, 0.02f, 2.0f },
        0.0f, 0.0f, 0.0f,
        { -6.4f, -0.001f, -0.2f }
    );

    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderColor(0.0f, 0.0f, 0.0f, 0.15f);

    meshes.DrawTaperedCylinderMesh();

    // Reset color
    scene.SetShaderColor(1.0f, 1.0f, 1.0f, 1.0f);


    // Base
    scene.SetTransformations({ 1.8f, 0.1f, 0.8f }, 0, 0, 0, { -6.0f, 0.0f, -0.5f });
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::LAPTOPFRAME, TextureTags::MOUSE, 0.20f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawBoxMesh();

    // Stand
    scene.SetTransformations({ 0.2f, 1.0f, 0.2f }, 0, 0, 0, { -6.0f, 0.0f, -0.5f });
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::LAPTOPFRAME, TextureTags::MOUSE, 0.10f);
    meshes.DrawTaperedCylinderMesh();

    // Screen frame
    const glm::vec3 FRAME_SCALE(6.0f, 4.0f, 0.2f);
    const glm::vec3 FRAME_POS(-6.0f, 3.0f, -0.5f);

    scene.SetTransformations(FRAME_SCALE, 0, 0, 0, FRAME_POS);
    scene.SetShaderTextureBlend(TextureTags::LAPTOPFRAME, TextureTags::MOUSE, 0.20f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawBoxMesh();

    // Thin front screen panel
    const glm::vec3 PANEL_SCALE(5.98f, 3.98f, 0.02f);
    const glm::vec3 PANEL_POS(-6.0f, 3.0f, -0.39f);

    scene.SetTransformations(PANEL_SCALE, 0, 0, 0, PANEL_POS);

    // Glow on
    scene.SetEmissiveStrength(0.25f);

    scene.SetShaderTextureBlend(TextureTags::SCREENS, TextureTags::BOOK3, 0.05f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawBoxMesh();

    // Glow off
    scene.SetEmissiveStrength(0.0f);
}

void MonitorsObject::RenderRightMonitor(SceneManager& scene, ShapeMeshes& meshes)
{
    // Shadow under monitor
    scene.SetTransformations(
        { 3.0f, 0.02f, 2.0f },
        0.0f, 0.0f, 0.0f,
        { 5.6f, -0.001f, -0.2f } 
    );

    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderColor(0.0f, 0.0f, 0.0f, 0.15f);

    meshes.DrawTaperedCylinderMesh();

    // Reset color
    scene.SetShaderColor(1.0f, 1.0f, 1.0f, 1.0f);


    // Base
    scene.SetTransformations({ 1.8f, 0.1f, 0.8f }, 0, 0, 0, { 6.0f, 0.0f, -0.5f });
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::LAPTOPFRAME, TextureTags::MOUSE, 0.20f);
    meshes.DrawBoxMesh();

    // Stand
    scene.SetTransformations({ 0.2f, 1.0f, 0.2f }, 0, 0, 0, { 6.0f, 0.0f, -0.5f });
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::LAPTOPFRAME, TextureTags::MOUSE, 0.10f);
    meshes.DrawTaperedCylinderMesh();

    // Screen frame
    const glm::vec3 FRAME_SCALE(6.0f, 4.0f, 0.2f);
    const glm::vec3 FRAME_POS(6.0f, 3.0f, -0.5f);

    scene.SetTransformations(FRAME_SCALE, 0, 0, 0, FRAME_POS);
    scene.SetShaderTextureBlend(TextureTags::LAPTOPFRAME, TextureTags::MOUSE, 0.20f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawBoxMesh();

    // Thin front screen panel
    const glm::vec3 PANEL_SCALE(5.98f, 3.98f, 0.02f);
    const glm::vec3 PANEL_POS(6.0f, 3.0f, -0.39f);

    scene.SetTransformations(PANEL_SCALE, 0, 0, 0, PANEL_POS);

    // Glow on
    scene.SetEmissiveStrength(0.25f);

    scene.SetShaderTextureBlend(TextureTags::SCREENS, TextureTags::BOOK3, 0.05f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawBoxMesh();

    // Glow off
    scene.SetEmissiveStrength(0.0f);
}
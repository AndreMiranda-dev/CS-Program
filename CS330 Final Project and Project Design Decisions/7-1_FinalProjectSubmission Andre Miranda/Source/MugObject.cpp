///////////////////////////////////////////////////////////////////////////////
// mugobject.cpp
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#include "MugObject.h"

void MugObject::Render(SceneManager& scene, ShapeMeshes& meshes)
{
    // Shadow under mug
    scene.SetTransformations(
        { 0.95f, 0.02f, 0.95f },
        0.0f, 0.0f, 0.0f,
        { -6.3f, -0.001f, 2.25f }
    );

    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderColor(0.0f, 0.0f, 0.0f, 0.15f);   // soft, subtle shadow

    meshes.DrawTaperedCylinderMesh();

    // Reset color
    scene.SetShaderColor(1.0f, 1.0f, 1.0f, 1.0f);


    glm::vec3 mugBasePos(-6.0f, 0.0f, 2.0f);

    // Mug body
    scene.SetTransformations({ 0.60f, 1.20f, 0.60f }, 0, 0, 0, mugBasePos);
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::MUG, TextureTags::CUP, 0.15f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawCylinderMesh();

    // Mug interior lip
    scene.SetTransformations({ 0.40f, 0.02f, 0.40f }, 0, 0, 0, mugBasePos + glm::vec3(0, 1.20f, 0));
    scene.SetShaderMaterial("flatTexture");
    scene.SetBoolValue("bUseTexture", false);
    scene.SetShaderColor(0.35f, 0.20f, 0.05f, 1.0f);
    meshes.DrawCylinderMesh();

    // Mug base
    scene.SetTransformations({ 0.55f, 0.10f, 0.55f }, 0, 0, 0, mugBasePos);
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::MUG, TextureTags::CUP, 0.15f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawTaperedCylinderMesh();

    // Mug handle
    scene.SetTransformations({ 0.30f, 0.55f, 0.12f }, 0, 0, 90, mugBasePos + glm::vec3(0.75f, 0.60f, 0));
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::MUG, TextureTags::CUP, 0.10f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawTorusMesh();
    scene.SetShaderMaterial("flatTexture");
    scene.SetBoolValue("bUseTexture", false);


    // Mug steam (simple transform, no billboard)
    glm::vec3 steamPos = mugBasePos + glm::vec3(0.0f, 1.45f, 0.0f);

    // Make the plane vertical and visible
    scene.SetTransformations(
        { 0.6f, 1.4f, 1.0f },   // scale X/Y, keep Z = 1
        90.0f,                  // rotate 90° around X so plane stands upright
        0.0f,
        0.0f,
        steamPos
    );

    scene.SetBoolValue("bSteam", true);
    meshes.DrawPlaneMesh();
    scene.SetBoolValue("bSteam", false);
}
///////////////////////////////////////////////////////////////////////////////
// mouseobject.cpp
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#include "MouseObject.h"

void MouseObject::Render(SceneManager& scene, ShapeMeshes& meshes)
{
    // Shadow under mouse
    scene.SetTransformations(
        { 0.55f, 0.02f, 0.40f },
        0.0f, 0.0f, 0.0f,
        { 2.7f, -0.001f, 2.25f }
    );

    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderColor(0.0f, 0.0f, 0.0f, 0.15f);

    meshes.DrawTaperedCylinderMesh();

    // Reset color
    scene.SetShaderColor(1.0f, 1.0f, 1.0f, 1.0f);
    scene.SetTransformations({ 0.35f, 0.30f, 0.20f }, 0, 0, 90, { 3.0f, 0.10f, 2.0f });
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::MOUSE, TextureTags::PENCIL, 0.10f);
    meshes.DrawCylinderMesh();
}
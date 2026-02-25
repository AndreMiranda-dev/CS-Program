///////////////////////////////////////////////////////////////////////////////
// booksobject.cpp
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#include "BooksObject.h"

void BooksObject::Render(SceneManager& scene, ShapeMeshes& meshes)
{
    // Shadow under books
    scene.SetTransformations(
        { 2.2f, 0.02f, 1.4f },
        0.0f, 0.0f, 0.0f,
        { -11.9f, -0.001f, 0.25f }
    );

    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderColor(0.0f, 0.0f, 0.0f, 0.15f);

    meshes.DrawTaperedCylinderMesh();

    // Reset color
    scene.SetShaderColor(1.0f, 1.0f, 1.0f, 1.0f);


    // Book 1
    scene.SetTransformations({ 1.8f, 0.3f, 1.0f }, 0, 10, 0, { -11.5f, 0.15f, 0.0f });
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::BOOK1, TextureTags::MUG, 0.20f);
    meshes.DrawBoxMesh();

    // Book 2
    scene.SetTransformations({ 1.6f, 0.3f, 0.9f }, 0, -5, 0, { -11.5f, 0.45f, 0.2f });
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::BOOK2, TextureTags::MUG, 0.20f);
    meshes.DrawBoxMesh();

    // Book 3
    scene.SetTransformations({ 1.4f, 0.3f, 0.8f }, 0, 3, 0, { -11.5f, 0.75f, -0.2f });
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::BOOK3, TextureTags::MUG, 0.20f);
    meshes.DrawBoxMesh();
}
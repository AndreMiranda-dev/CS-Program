///////////////////////////////////////////////////////////////////////////////
// pencilcupobject.cpp
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#include "PencilCupObject.h"

void PencilCupObject::Render(SceneManager& scene, ShapeMeshes& meshes)
{
    // Shadow under pencil cup
    scene.SetTransformations(
        { 1.1f, 0.02f, 1.1f },
        0.0f, 0.0f, 0.0f,
        { -3.3f, -0.001f, 2.25f }
    );

    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderColor(0.0f, 0.0f, 0.0f, 0.15f);

    meshes.DrawTaperedCylinderMesh();

    // Reset color
    scene.SetShaderColor(1.0f, 1.0f, 1.0f, 1.0f);


    RenderCup(scene, meshes);
    RenderPencils(scene, meshes);
}

void PencilCupObject::RenderCup(SceneManager& scene, ShapeMeshes& meshes)
{
    glm::vec3 cupPos(-3.0f, 0.0f, 2.0f);

    // Cup outer wall
    scene.SetTransformations({ 0.5f, 1.0f, 0.5f }, 0, 0, 0, cupPos);
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::CUP, TextureTags::BOOK1, 0.15f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawCylinderMesh();

    // Cup inner lip
    scene.SetTransformations({ 0.35f, 0.02f, 0.35f }, 0, 0, 0, cupPos + glm::vec3(0, 0.985f, 0));
    scene.SetShaderMaterial("flatTexture");
    scene.SetBoolValue("bUseTexture", false);
    scene.SetShaderColor(0.0f, 0.0f, 0.0f, 1.0f);
    meshes.DrawCylinderMesh();
}

void PencilCupObject::RenderPencils(SceneManager& scene, ShapeMeshes& meshes)
{
    for (int i = 0; i < 5; i++)
    {
        float xOffset = -3.0f + ((i % 2 == 0) ? -0.10f : 0.10f);
        float zOffset = 2.0f + ((i % 3 == 0) ? -0.10f : 0.10f);
        float tilt = (i % 2 == 0) ? 8.0f : -6.0f;

        // Pencil body base position
        glm::vec3 basePos(xOffset, 0.35f, zOffset);

        // Pencil body
        scene.SetTransformations({ 0.08f, 1.0f, 0.08f }, tilt, 0, 0, basePos);
        scene.SetShaderMaterial("flatTexture");
        scene.SetShaderTextureBlend(TextureTags::PENCIL, TextureTags::DESKWOOD, 0.10f);
        meshes.DrawCylinderMesh();

        // Direction of pencil axis after tilt
        float rad = glm::radians(tilt);
        glm::vec3 dir(0.0f, cos(rad), sin(rad));

        // Pencil tip position
        glm::vec3 tipPos = basePos + dir * 1.0f;

        // Pencil tip
        scene.SetTransformations({ 0.08f, 0.20f, 0.08f }, tilt, 0, 0, tipPos);
        scene.SetShaderMaterial("flatTexture");
        scene.SetBoolValue("bUseTexture", true);
        scene.SetShaderTextureBlend(TextureTags::BOOK3, TextureTags::BOOK3, 0.10f);
        scene.SetShaderColor(0.20f, 0.20f, 0.20f, 1.0f);
        meshes.DrawConeMesh();
    }
}
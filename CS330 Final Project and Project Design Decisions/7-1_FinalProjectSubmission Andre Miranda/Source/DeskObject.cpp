///////////////////////////////////////////////////////////////////////////////
// deskobject.cpp
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#include "DeskObject.h"

void DeskObject::Render(SceneManager& scene, ShapeMeshes& meshes)
{
    const glm::vec3 DESK_SCALE(20.0f, 1.0f, 10.0f);
    const glm::vec3 DESK_POSITION(0.0f, 0.0f, 0.0f);
    const float DESK_ROT_X = 0.0f;
    const float DESK_ROT_Y = 0.0f;
    const float DESK_ROT_Z = 0.0f;
    const float DESK_UV_U = 1.0f;
    const float DESK_UV_V = 1.0f;

    scene.SetTransformations(DESK_SCALE, DESK_ROT_X, DESK_ROT_Y, DESK_ROT_Z, DESK_POSITION);
    scene.SetShaderTextureBlend(TextureTags::DESKWOOD, TextureTags::CUP, 0.20f);
    scene.SetShaderMaterial("desk");
    scene.SetTextureUVScale(DESK_UV_U, DESK_UV_V);
    meshes.DrawPlaneMesh();



    // Desk thickness
    scene.SetTransformations(
        { 40.0f, 0.5f, 20.0f },
        0.0f, 0.0f, 0.0f,
        { 0.0f, -0.35f, 0.0f }
    );
    scene.SetShaderTextureBlend(TextureTags::DESKWOOD, TextureTags::CUP, 0.20f);
    scene.SetShaderMaterial("desk");
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawBoxMesh();
}
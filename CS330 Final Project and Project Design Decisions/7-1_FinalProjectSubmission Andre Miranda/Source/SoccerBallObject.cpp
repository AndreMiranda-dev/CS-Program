///////////////////////////////////////////////////////////////////////////////
// SoccerBallObject.cpp
//
//  AUTHOR: André Miranda
//  Realistic soccer ball sized correctly next to 27-inch monitors
///////////////////////////////////////////////////////////////////////////////

#include "SoccerBallObject.h"

void SoccerBallObject::Render(SceneManager& scene, ShapeMeshes& meshes)
{
    // Desk surface height
    const float DESK_Y = 0.5f;

    // Soccer ball size + position
    const float BALL_SCALE = 1.3f;
    const float BALL_X = 9.5f;
    const float BALL_Z = 2.4f;
    const float BALL_Y = (DESK_Y + BALL_SCALE) - 0.55f;

    // Shadow under soccer ball
    scene.SetTransformations(
        { BALL_SCALE * 1.2f, 0.02f, BALL_SCALE * 1.2f },   // slightly larger than ball
        0.0f, 0.0f, 0.0f,
        { BALL_X, -0.001f, BALL_Z }   // <-- moved down to desk surface
    );

    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderColor(0.0f, 0.0f, 0.0f, 0.15f);
    meshes.DrawTaperedCylinderMesh();

    // Reset color
    scene.SetShaderColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Soccer ball
    scene.SetTransformations(
        { BALL_SCALE, BALL_SCALE, BALL_SCALE },
        0.0f, 0.0f, 0.0f,
        { BALL_X, BALL_Y, BALL_Z }
    );
    scene.SetShaderMaterial("flatTexture");
    scene.SetShaderTextureBlend(TextureTags::SOCCERBALL, TextureTags::BOOK3, 0.08f);
    scene.SetTextureUVScale(1.0f, 1.0f);
    meshes.DrawSphereMesh();
}
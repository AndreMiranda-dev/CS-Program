///////////////////////////////////////////////////////////////////////////////
// SoccerBallObject.h
//
//  AUTHOR: André Miranda
//  Realistic soccer ball using the sphere mesh
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneObject.h"

class SoccerBallObject : public SceneObject
{
public:
    virtual void Render(SceneManager& scene, ShapeMeshes& meshes) override;
};
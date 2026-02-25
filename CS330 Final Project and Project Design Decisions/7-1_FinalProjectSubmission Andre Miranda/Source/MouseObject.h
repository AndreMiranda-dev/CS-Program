///////////////////////////////////////////////////////////////////////////////
// mouseobject.h
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneObject.h"

/***********************************************************
 *  MouseObject
 *
 *  Represents the computer mouse in the 3D scene.
 ***********************************************************/
class MouseObject : public SceneObject
{
public:
    void Render(SceneManager& scene, ShapeMeshes& meshes) override;
};
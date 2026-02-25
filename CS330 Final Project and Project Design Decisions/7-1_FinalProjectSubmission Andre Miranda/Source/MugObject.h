///////////////////////////////////////////////////////////////////////////////
// mugobject.h
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneObject.h"

/***********************************************************
 *  MugObject
 ***********************************************************/
class MugObject : public SceneObject
{
public:
    void Render(SceneManager& scene, ShapeMeshes& meshes) override;
};
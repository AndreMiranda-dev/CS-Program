///////////////////////////////////////////////////////////////////////////////
// deskobject.h
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneObject.h"

/***********************************************************
 *  DeskObject
 ***********************************************************/
class DeskObject : public SceneObject
{
public:
    void Render(SceneManager& scene, ShapeMeshes& meshes) override;
};
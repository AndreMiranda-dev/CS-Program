///////////////////////////////////////////////////////////////////////////////
// booksobject.h
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneObject.h"

/***********************************************************
 *  BooksObject
 ***********************************************************/
class BooksObject : public SceneObject
{
public:
    void Render(SceneManager& scene, ShapeMeshes& meshes) override;
};
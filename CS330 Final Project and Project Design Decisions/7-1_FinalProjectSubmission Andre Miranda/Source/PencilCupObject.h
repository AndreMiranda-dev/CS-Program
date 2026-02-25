///////////////////////////////////////////////////////////////////////////////
// pencilcupobject.h
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneObject.h"

/***********************************************************
 *  PencilCupObject
 ***********************************************************/
class PencilCupObject : public SceneObject
{
public:
    void Render(SceneManager& scene, ShapeMeshes& meshes) override;

private:
    static void RenderCup(SceneManager& scene, ShapeMeshes& meshes);
    static void RenderPencils(SceneManager& scene, ShapeMeshes& meshes);
};
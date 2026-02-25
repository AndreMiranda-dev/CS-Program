///////////////////////////////////////////////////////////////////////////////
// laptopobject.h
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneObject.h"

/***********************************************************
 *  LaptopObject
 ***********************************************************/
class LaptopObject : public SceneObject
{
public:
    void Render(SceneManager& scene, ShapeMeshes& meshes) override;

private:
    static void RenderKeys(SceneManager& scene, ShapeMeshes& meshes);
    static void RenderTrackpad(SceneManager& scene, ShapeMeshes& meshes);
    static void RenderPowerButton(SceneManager& scene, ShapeMeshes& meshes);
};
///////////////////////////////////////////////////////////////////////////////
// keyboardobject.h
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneObject.h"

/***********************************************************
 *  KeyboardObject
 ***********************************************************/
class KeyboardObject : public SceneObject
{
public:
    void Render(SceneManager& scene, ShapeMeshes& meshes) override;

private:
    static void RenderBase(SceneManager& scene, ShapeMeshes& meshes);
    static void RenderKeys(SceneManager& scene, ShapeMeshes& meshes);
};
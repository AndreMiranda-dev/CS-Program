///////////////////////////////////////////////////////////////////////////////
// sceneobject.h
// ============
// base class for encapsulated 3D scene objects
//
//  AUTHOR: André Miranda (based on SNHU CS-330 structure)
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ShapeMeshes.h"
#include "SceneManager.h"

/***********************************************************
 *  SceneObject
 *
 *  Abstract base class for all encapsulated 3D scene objects.
 *  Each derived class must implement its own Render() method.
 ***********************************************************/
class SceneObject
{
public:
    // virtual destructor
    virtual ~SceneObject() = default;

    // render the object using the provided scene manager and meshes
    virtual void Render(SceneManager& scene, ShapeMeshes& meshes) = 0;
};
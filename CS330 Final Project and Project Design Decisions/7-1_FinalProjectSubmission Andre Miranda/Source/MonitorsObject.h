///////////////////////////////////////////////////////////////////////////////
// monitorsobject.h
//
//  AUTHOR: André Miranda
//  Created for CS-330-Computational Graphics and Visualization
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SceneObject.h"

/***********************************************************
 *  MonitorsObject
 ***********************************************************/
class MonitorsObject : public SceneObject
{
public:
    void Render(SceneManager& scene, ShapeMeshes& meshes) override;

private:
    static void RenderLeftMonitor(SceneManager& scene, ShapeMeshes& meshes);
    static void RenderRightMonitor(SceneManager& scene, ShapeMeshes& meshes);
};
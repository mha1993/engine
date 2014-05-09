//
//  PhysicsUtil.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-08.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__PhysicsUtil__
#define __Engine__PhysicsUtil__

#include <iostream>
#include "glm.hpp"
#include <vector>

#endif /* defined(__Engine__PhysicsUtil__) */


glm::vec3 calcNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);

bool pointOnLineSeg(glm::vec3 v1, glm::vec3 v2, glm::vec3 point);

bool pointInPoly3D(std::vector<glm::vec3> verts, glm::vec3 point);

float distanceFromPlane(glm::vec3 pointOnPlane, glm::vec3 planeNormal, glm::vec3 point);

bool d0(float a, float b);

//
//  PhysicsPlane.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-08.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__PhysicsPlane__
#define __Engine__PhysicsPlane__

#include <iostream>

#include "glm.hpp"
#include <vector>


#endif /* defined(__Engine__PhysicsPlane__) */

class PhysicsObject;


using namespace std;

class PhysicsPlane{

    glm::vec3 normal;
    
    vector<glm::vec3> verts;
    
    
public:
    PhysicsPlane(vector<glm::vec3> vertecis);
    void addNormal(glm::vec3 v);
    float collisionTime(PhysicsObject *po);
    vector<glm::vec3> getVerts();
    glm::vec3 getNormal();
};

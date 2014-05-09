//
//  PhysicsPlane.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-08.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PhysicsPlane.h"
#include "PhysicsObject.h"


PhysicsPlane::PhysicsPlane(vector<glm::vec3> _verts){

    verts = _verts;
    
}


void PhysicsPlane::addNormal(glm::vec3 v){

    normal = v;
}

float PhysicsPlane::collisionTime(PhysicsObject::PhysicsObject *po){
    
    return -1;
    
}
//
//  PObject2.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-24.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__PObject2__
#define __Engine__PObject2__

#include <iostream>
#include "PhysicShape.h"
#include "glm.hpp"

using namespace glm;

class PObject{
    
public:
    int id;
    bool isStatic;
    bool collidable;
    vec3 pos;
    vec3 vel;
    PhysicShape * ps;
    float size;
    
    
    PObject(int id, PhysicShape * ps, vec3 pos, bool collidable);
    PObject(int id, PhysicShape * ps, vec3 pos, vec3 vel, bool collidable, float size, bool isStatic);
    
};




#endif /* defined(__Engine__PObject2__) */
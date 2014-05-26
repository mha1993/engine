//
//  PhysicShape.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-24.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__PhysicShape__
#define __Engine__PhysicShape__

#include <iostream>
#include "glm.hpp"

using namespace glm;

class PhysicShape{
    
public:
    virtual vec3 mSupport(vec3 dir);

};



#endif /* defined(__Engine__PhysicShape__) */
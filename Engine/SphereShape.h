//
//  SphereShape.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__SphereShape__
#define __Engine__SphereShape__

#include <iostream>

#include "PhysicShape.h"

#include <string>

class SphereShape : public PhysicShape{

public:
    vec3 mSupport(vec3 dir);
    
    std::string getName();

};


#endif /* defined(__Engine__SphereShape__) */

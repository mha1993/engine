//
//  Force.h
//  Engine
//
//  Created by Mats Allen on 5/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Force__
#define __Engine__Force__

#include <iostream>

#include "glm.hpp"

class Force {
    
public:
    virtual glm::vec3 calcForce(float dt);
};

#endif /* defined(__Engine__Force__) */



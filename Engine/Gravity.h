//
//  Gravity.h
//  Engine
//
//  Created by Mats Allen on 6/7/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Gravity__
#define __Engine__Gravity__

#include <iostream>
#include "Force.h"

class Gravity : Force {
    
public:
    virtual glm::vec3 calcForce(float dt) override;
};

#endif /* defined(__Engine__Gravity__) */

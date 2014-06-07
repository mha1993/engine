//
//  Gravity.cpp
//  Engine
//
//  Created by Mats Allen on 6/7/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Gravity.h"


glm::vec3 Gravity::calcForce(float dt){
    
    return dt * glm::vec3(0.0,-0.1,0.0);
    
}
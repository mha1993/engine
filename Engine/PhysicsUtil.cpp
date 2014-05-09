//
//  PhysicsUtil.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-08.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PhysicsUtil.h"



glm::vec3 calcNormal(glm::vec3 a, glm::vec3 b, glm::vec3 c){

    
    b = b - a;
    c = c - a;
    
    glm::vec3 norm = glm::cross(b, c);
    norm = glm::normalize(norm);

    return norm;
    
}
//
//  PhysicsObject.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-07.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__PhysicsObject__
#define __Engine__PhysicsObject__

#include <iostream>
#include <glm.hpp>


class PhysicsObject{
    
    glm::vec3 position;
    glm::vec3 velocity;
    
    glm::mat4 scaleMatrix;
    glm::mat4 translateMatrix;
    
public:
    glm::vec3 getPosition();
    glm::vec3 getVelocity();
    glm::mat4 getModelMatrix();
    void scale(glm::mat4 s);
    
    void setPosition(glm::vec3 _p);
    void setVelocity(glm::vec3 _v);
    void offsetPosition(glm::vec3 _p);
    void offsetVelocity(glm::vec3 _v);
    
    PhysicsObject();
    
};



#endif /* defined(__Engine__PhysicsObject__) */

//
//  FollowCamera.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-13.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "FollowCamera.h"

FollowCamera::FollowCamera(PhysicsObject *po){

    followObject = po;

}


void FollowCamera::update(float time){

    glm::vec3 v = followObject->getVelocity();
    
    v = glm::vec3(v.x,0,v.z);
    
    v = glm::normalize(v);
    
    v *= 2.0;
    
    setPosition( (followObject->getPosition() - v) + glm::vec3(0.0,1.0,0.0));
    
    lookAt(followObject->getPosition());
    
}
//
//  FollowCamera.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-13.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "FollowCamera.h"
#include "PhysicsUtil.h"

#include <glm/gtx/vector_angle.hpp>

FollowCamera::FollowCamera(PObject *po){

    followObject = po;

}


void FollowCamera::update(float time){

    
    float moveSpeed = 1.0;
    
    float ballDist = 2.0;
    
    glm::vec3 v = followObject->vel;
    
    v = glm::vec3(v.x,0,v.z);
    
    v = glm::normalize(v);
    
    v *= ballDist;
    
    
    glm::vec3 newPos = followObject->pos - v + glm::vec3(0.0,1.0,0.0);
    
    glm::vec3 diff =  newPos - lastPos;
    
    float len = glm::length(diff);
    
    if (len > time * moveSpeed){
        
    }
    
    glm::vec3 dir = glm::normalize(diff);
    
    
    
    
    setPosition(newPos);
    
    lookAt(followObject->pos);
    
}
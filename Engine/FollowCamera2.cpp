//
//  FollowCamera2.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-13.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "FollowCamera2.h"
#include "PhysicsUtil.h"

#include <glm/gtx/vector_angle.hpp>

FollowCamera2::FollowCamera2(PObject *po){
    followObject = po;
}


void FollowCamera2::update(float time){
    vec3 vel = -normalize(followObject->vel);
    vel.y = 0.5;
    setPosition(followObject->pos + vel);
    lookAt(followObject->pos);
    
}
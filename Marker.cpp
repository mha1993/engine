//
//  Marker.cpp
//  Engine
//
//  Created by Mats Allen on 6/12/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Marker.h"
#include "GameObject.h"

void Marker::tick(float dt){
    physicsObject->vel = vec3(0,0,0);
}

Marker::Marker(glm::vec3 pos, glm::vec3 vel, float size, int idd) : Ball(pos, vel, size, idd) {
    
}
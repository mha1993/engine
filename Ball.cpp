//
//  Ball.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Ball.h"

#include "SphereShape.h"

#include "DrawableSphere.h"

Ball::Ball(glm::vec3 pos, float size, int idd) : GameObject(idd){


    PhysicShape *pss = new SphereShape();
    physicsObject = new PObject(idd, pss, pos, vec3(0.0,0.0,0.0), true, size, false);

    mesh = new DrawableSphere(size, 10, 10, "default.vs","red.fsh");
    
    

}

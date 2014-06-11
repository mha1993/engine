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


Ball::Ball(glm::vec3 pos, glm::vec3 vel, float size, int idd) : GameObject(idd){
    
    setIdentifier("BALL");

    PhysicShape *pss = new SphereShape();
    physicsObject = new PObject(idd, pss, pos, vel, true, size, false);

    mesh = new DrawableSphere(size, 10, 10, "default.vs","red.fsh");
}

void Ball::collidedWith(GameObject *other, vec3 hitNormal, vec3 pos) {

    
    vec3 n = normalize(hitNormal);
    vec3 d = getPhysicsObject()->vel;
    
    
    if (other->identifier.compare("WALL") == 0){
        
        vec3 reflection = d-2*(dot(d,n))*n;
        physicsObject->vel = reflection * .8f;
        
    }else{
        
        physicsObject->vel = (d - dot(d,n) * n ) *.999f;
    
    }
}


std::string Ball::name(){
    return "Ball";
}
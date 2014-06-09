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
    //float bounceCoefficient = 0.8f;
    vec3 n = normalize(hitNormal);
    vec3 d = getPhysicsObject()->vel;
    
    vec3 normalizedNormal = normalize(n);
    vec3 normalizedDir = normalize(d);
    
    float dott = dot(normalizedNormal,normalizedDir);
    
    float bounce = 0.8;
    
    printf("col : %f\n",bounce);
    printf("   vel = %f\n", length(physicsObject->vel));
    vec3 reflection = d-2*(dot(d,n))*n;
    getPhysicsObject()->vel =  bounce*reflection;
    
//    
//    if (fabsf(dott) > .3 && length(physicsObject->vel) > 0.1){
//        vec3 reflection = d-2*(dot(d,n))*n;
//        getPhysicsObject()->vel =  bounceCoefficient*reflection;
//    }else{
//        //getPhysicsObject()->vel -= getPhysicsObject()->vel * 0.001f;
//    }
    
}
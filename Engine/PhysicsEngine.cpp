 //
//  PhysicsEngine.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-07.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PhysicsEngine.h"
#include "PhysicsPlane.h"
#include "PhysicsUtil.h"
#include <vector>

void PhysicsEngine::addMovableObject(PhysicsObject *po) {
    movableObjects.push_back(po);
}
void PhysicsEngine::addPlane(PhysicsPlane *po) {
    imovableObjects.push_back(po);
}

PhysicsPlane* PhysicsEngine::getCurrentTile() {
    PhysicsObject *ball = movableObjects[0];
    glm::vec3 ballPosition = ball->getPosition();
    
    bool jakob = false;
    
    for (int i = 0; i < imovableObjects.size(); i++) {
        
        PhysicsPlane *pp = imovableObjects[i];
        
        float dfp = distanceFromPlane(pp->getVerts()[0],pp->getNormal(), ballPosition);
        
        if (d0(dfp, ball->getRadius())){
            if (pointInPoly3D(pp->getVerts(), ballPosition)) {
                std::cout << i << std::endl;
                return pp;
            }
        }else{
            jakob = true;
        }
    }
    
    if (!jakob){
        printf("DSAHDHSAHDSAS\n");
        exit(321);
    }
    
    return NULL;
}

void PhysicsEngine::calcForces() {
    PhysicsPlane*tile = getCurrentTile();
    
    if (tile == NULL){
        return;
    }
    
    glm::vec3 n = tile->getNormal();
    glm::vec3 v = movableObjects[0]->getVelocity();
    movableObjects[0]->setVelocity(-(n*(glm::dot(v, n))-v));
    
}

void PhysicsEngine::tick(float deltaT) {
    calcForces();
    updatePositions(deltaT);
}

void PhysicsEngine::updatePositions(float deltaT) {
    for (int i=0; i<movableObjects.size(); i++) {
        glm::vec3 vel = movableObjects[i]->getVelocity();
        movableObjects[i]->offsetPosition(deltaT*vel);
    }
}


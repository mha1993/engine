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
    for (int i = 0; i < imovableObjects.size(); i++) {
        if (pointInPoly(imovableObjects[i]->getVerts(), ballPosition)) {
            std::cout << i << std::endl;
            return imovableObjects[i];
        }
    }
    
    std::cout << "aNOOOO" << std::endl;
    
    return NULL;
}

void PhysicsEngine::calcForces() {
    PhysicsPlane*tile = getCurrentTile();
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


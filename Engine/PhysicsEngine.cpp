//
//  PhysicsEngine.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-07.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PhysicsEngine.h"

#include <vector>

void PhysicsEngine::addMovableObject(PhysicsObject *po) {
    movableObjects.push_back(po);
}
void PhysicsEngine::addImovableObject(PhysicsObject *po) {
    imovableObjects.push_back(po);
}

void PhysicsEngine::updatePositions(float deltaT) {
    for (int i=0; i<movableObjects.size(); i++) {
        glm::vec3 vel = movableObjects[i]->getVelocity();
        movableObjects[i]->offsetPosition(deltaT*vel);
    }
}


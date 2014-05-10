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
        
        PhysicsPlane *pp = imovableObjects[i];
       
        //float dfp = distanceFromPlane(pp->getVerts()[0],pp->getNormal(), ballPosition);
        //if (d0(dfp, ball->getRadius())){
            if (onTile(pp->getVerts(), ballPosition)) {
                //std::cout << i << std::endl;
                return pp;
            }
        //}
    }
    
    return NULL;
}

void PhysicsEngine::calcForces() {
    
    PhysicsPlane *tile = getCurrentTile();
    
    if (tile == NULL){
        return;
    }
    
    glm::vec3 n = tile->getNormal();
    glm::vec3 v = movableObjects[0]->getVelocity();
    
    glm::vec3 newV = -(n*(glm::dot(v, n))-v);
    
    movableObjects[0]->setVelocity(newV);
    
}

float PhysicsEngine::nextCol(vector<PhysicsObject*> movable,vector<PhysicsPlane*> imovable){
    
    PhysicsObject *po = movable[0];
    
    glm::vec3 ballVel = po->getVelocity();
    glm::vec3 ballPos = po->getPosition();
    
    float colTime = -1;
    
    for (int i = 0; i<imovable.size() ; i++){
        
        PhysicsPlane *pp = imovable[i];
        glm::vec3 norm = pp->getNormal();
        
        glm::vec3 pointOnPlane = pp->getVerts()[0];
        
        if (d0(glm::dot(norm, ballVel),0.0)){
            continue;
        }
        
        glm::vec3 p = ballPos + (norm * po->getRadius());
        
        float c = glm::dot((pointOnPlane - p),norm)/ glm::dot(ballVel,norm);
        
        if (c > 0 && (colTime < 0 || c < colTime)){
            
            glm::vec3 hitPoint = p + c * ballVel;

            if (pointInPoly3Ds(pp->getVerts(), hitPoint)){
            
                colTime = c;
                ballCol = po;
                planeCol = pp;
                
            }
        }
    }
    return colTime;
}

void PhysicsEngine::resolve(){
    
    
    glm::vec3 normal = planeCol->getNormal();
    glm::vec3 vel = ballCol->getVelocity();
    glm::vec3 newVec = vel - (normal * (glm::dot(vel, normal) * 2.0f));
    
    
    ballCol->setVelocity(newVec);
    
    planeCol = nullptr;
    ballCol = nullptr;
    
}

void PhysicsEngine::tick(float deltaT) {
    calcForces();
    
    float timeLeft = deltaT;
    
    
    int nrloops = 0;
    
    while (timeLeft > 0) {
        
        float nextColision = nextCol(movableObjects,imovableObjects);
        
        if ( nextColision < 0.0 || nextColision >= timeLeft){
            updatePositions(timeLeft);
            timeLeft = 0;
        }else{
            updatePositions(nextColision);
            resolve();
            timeLeft -= nextColision;
        }
        nrloops++;
    }

}

void PhysicsEngine::updatePositions(float deltaT) {
    for (int i=0; i<movableObjects.size(); i++) {
        glm::vec3 vel = movableObjects[i]->getVelocity();
        movableObjects[i]->offsetPosition(deltaT*vel);
    }
}


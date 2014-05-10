//
//  PhysicsEngine.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-07.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__PhysicsEngine__
#define __Engine__PhysicsEngine__

#include <iostream>
#include "PhysicsObject.h"
#include <vector>


#endif /* defined(__Engine__PhysicsEngine__) */

using namespace std;


class PhysicsPlane;

class PhysicsEngine{
    
    vector<PhysicsPlane *> imovableObjects;
    vector<PhysicsObject *> movableObjects;
    
    PhysicsObject *firstCollisionObjectA;
    
    float nextColTime;
    
public:
    void addMovableObject(PhysicsObject *po);
    void addPlane(PhysicsPlane *po);
    
    void tick(float deltaT);
    
private:
    
    PhysicsPlane *planeCol;
    PhysicsObject *ballCol;
    
    void resolve();
    
    void updatePositions(float deltaT);
    PhysicsPlane* getCurrentTile();
    void calcForces();
    float nextCol(vector<PhysicsObject*> movable,vector<PhysicsPlane*> imovable);;
};
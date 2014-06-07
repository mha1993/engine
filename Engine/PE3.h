//
//  PE3.h
//  Engine
//
//  Created by Mats Allen on 5/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__PE3__
#define __Engine__PE3__

#include <iostream>
#include <vector>
#include "Force.h"
#include "PObject.h"

using namespace std;

struct Collision {
    int obj1;
    int obj2;
    glm::vec3 pos;
    glm::vec3 norm;
    
};

class PE3 {
    vector<Force*> forces;
    vector<Collision> collisions;
    
public:
    vector<Collision> getCollisions();
    void tick(vector<PObject*> objs, float dTime);
    void calcForces(PObject* obj);
    void move(PObject* obj, float dTime);
    glm::vec3 support(PObject* obj1, PObject* obj2, glm::vec3 d);
    void moveBack(PObject *ob1, PObject *ob2);
};

#endif /* defined(__Engine__PE3__) */

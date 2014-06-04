//
//  PE3.cpp
//  Engine
//
//  Created by Mats Allen on 5/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PE3.h"

#include "PhysicsUtil.h"


void PE3::calcForces(PObject* obj) {
    for (int i = 0; i < forces.size(); i++) {
        obj->vel += forces[i]->calcForce();
    }
}

void PE3::move(PObject* obj, float dTime){
    obj->pos += dTime*obj->vel;
}

glm::vec3 PE3::support(PObject* obj1, PObject* obj2, glm::vec3 d) {
    return obj1->ps->mSupport(d) - obj2->ps->mSupport(-d);
}

bool PE3::doSimplex(vector<glm::vec3> simplex, glm::vec3 d) {
    
    return false;
}

bool PE3::boundingBoxCheck(PObject* obj1, PObject* obj2) {
    vector<glm::vec3> simplex;
    
    glm::vec3 s = support(obj1, obj2, glm::vec3(1,0,0));
    simplex.push_back(s);
    glm::vec3 d = -s;
    
    while (true) {
        glm::vec3 a = support(obj1, obj2, d);
        if (glm::dot(a, d)) {
            return false;
        } else {
            simplex.push_back(a);
            if (doSimplex(simplex, d)) {
                return true;
            }
        }
    }
}

vector<Collision> PE3::getCollisions(){
    return collisions;
}

void PE3::moveBack(Collision c) {
    
}

void PE3::tick(vector<PObject*> objs, float dTime) {
    //CLEAR COLLISIONS
    collisions.clear();
    
    //FORCES
    for (int i = 0; i < objs.size(); i++) {
        calcForces(objs[i]);
    }
    
    //MOVE
    for (int i = 0; i < objs.size(); i++) {
        move(objs[i], dTime);
    }
    
    //CHECK COLLISIONS
    for (int i = 0; i < objs.size(); i++) {
        for (int j = 0; j < objs.size(); j++) {
            if (i==j) continue;
            if (boundingBoxCheck(objs[i], objs[j]))
                cout << "COLLISION HAPPENED" << endl;
        }
    }
    
    //MOVEBACK
    for (int i = 0; i < collisions.size(); i++) {
        moveBack(collisions[i]);
    }
}
//
//  Physics2.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-24.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Physics2.h"

int Physics2::idCounter = 0;

Physics2::Physics2(){

}


int Physics2::addObject(int physicsShape, float size, vector<vec3> vert, vec3 pos, vec3 vel, bool movable, bool collidable){

    PhysicShape *ps = nullptr;
    
    if (physicsShape == SHAPE_CONVEX_POLY){
        
        if (vert.size() < 3){
            throw std::runtime_error(std::string("poly shape needs to bee at least 3 points"));
        }
        ps = new PolygonShape(vert); // this should be moved so that physics only knows about PhysicShape
    }else{
        throw std::runtime_error(std::string("Shape not yet supported"));
    }
    
    int id = ++Physics2::idCounter;
    
    PObject *po = new PObject(id, ps, pos, vel, collidable, size,true);
    
    if (movable){
        mv.push_back(po);
    }else{
        im.push_back(po);
    }
    
    all[id] = po;
    
    return id;
}

vec3 Physics2::getVel(int id){
    return getObject(id)->vel;
}
vec3 Physics2::getPos(int id){
    return getObject(id)->pos;
}
float Physics2::getSize(int id){
    return getObject(id)->size;
}


void Physics2::setVel(int id,vec3 v){
    getObject(id)->vel = v;
}
void Physics2::setPos(int id, vec3 p){
    getObject(id)->pos = p;
}
void Physics2::setSize(int id,float s){
    getObject(id)->size = s;
}

PObject * Physics2::getObject(int id){
    
    hash_map<int, PObject *>::iterator i = all.find(id);
    
    if (i == all.end()) {
        /* Not found */
        throw std::runtime_error(std::string("WTF are you doing?!"));
    }
    else {
        return i->second;
    }    
}

void Physics2::tick(float tickTime){

    for (int i = 0; i<mv.size(); i++) {
        mv[i]->pos += mv[i]->vel * tickTime;
    }
}
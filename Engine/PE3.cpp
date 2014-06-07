//
//  PE3.cpp
//  Engine
//
//  Created by Mats Allen on 5/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PE3.h"

#include "PhysicsUtil.h"
#include "PolygonShape.h"
#include <math.h>

void PE3::addForce(Force *force) {
    forces.push_back(force);
}

void PE3::calcForces(PObject* obj, float dt) {
    for (int i = 0; i < forces.size(); i++) {
        obj->vel += forces[i]->calcForce(dt);
    }
}

void PE3::move(PObject* obj, float dTime){
    obj->pos += dTime*obj->vel;
}

vec3 CalcNormal(vector<vec3> verts) {
    vec3 a = verts[0];
    vec3 b = verts[1];
    vec3 c = verts[2];
    
    return cross(b-a, c-a);
}

vec3 LinePlaneIntersect(vec3 pNorm, vec3 pPoint, vec3 lPoint, vec3 lDir) {
    float d = dot((pPoint - lPoint), pNorm)/dot(lDir, pNorm);
    return d * lDir + lPoint;
}

float Magnitude(vec3 v) {
    return sqrt(pow(v.x, 2)+pow(v.y, 2)+pow(v.z, 2));
}

float AngleBetweenPoints(vec3 a, vec3 b, vec3 c) {
    vec3 v1 = b-a;
    vec3 v2 = c-a;
    return acos(dot(v1, v2)/Magnitude(v1)/Magnitude(v2));
}

bool PointInPoly(vec3 p, vector<vec3> verts) {
    float angleSum = 0;
    for (int i = 0; i<verts.size(); i++) {
        angleSum += AngleBetweenPoints(p, verts[i], verts[(i+1)%verts.size()]);
    }
    if (angleSum < 2*M_PI)
        return false;
    else
        return true;
}

bool SpherePlaneCollision(PObject *a, PObject *b) {
    vec3 sPos = a->pos;
    PolygonShape *ps = (PolygonShape*)b->ps;
    vector<vec3> verts = ps->PolygonShape::getVerts();
    
    for (int i = 0; i<verts.size(); i++) {
        verts[i] += b->pos;
    }
    
    vec3 norm = CalcNormal(verts);
    vec3 intersect = LinePlaneIntersect(norm, verts[0], sPos, -norm);

    
    if (distance(sPos, intersect) > a->size) {
        return false;
    } else {
        return PointInPoly(intersect, verts);
    }
}

vector<Collision> PE3::getCollisions(){
    return collisions;
}

void PE3::moveBack(PObject *ob1, PObject *ob2) {
    PolygonShape *tile = (PolygonShape*)ob2->ps;
    vec3 norm = CalcNormal(tile->getVerts());
    vec3 intersect = LinePlaneIntersect(norm, tile->getVerts()[0], ob1->pos, ob1->vel);
    vec3 move = ob1->pos - intersect;
    ob1->pos += move;
}

void PE3::tick(vector<PObject*> objs, float dTime) {
    //CLEAR COLLISIONS
    collisions.clear();
    
    vector<PObject*> moveables;
    vector<PObject*> imoveables;
    
    for (int i = 0; i<objs.size(); i++) {
        if (!objs[i]->isStatic) {
            moveables.push_back(objs[i]);
        }else{
            imoveables.push_back(objs[i]);
        }
    }
    
    //FORCES
    for (int i = 0; i < moveables.size(); i++) {
        calcForces(moveables[i], dTime);
    }
    
    //MOVE
    for (int i = 0; i < moveables.size(); i++) {
        move(moveables[i], dTime);
    }

    
    //CHECK COLLISIONS MOVABLE - IMOVABLE
    for (int i = 0; i < moveables.size(); i++) {
        
        PObject *a = moveables[i];
        
        for (int j = 0; j < imoveables.size(); j++) {
            
            PObject *b = imoveables[j];
            if (SpherePlaneCollision(a, b)){
                cout << "COLLISION" << endl;
                Collision c;
                moveBack(a, b);
                c.obj1 = a->id;
                c.obj2 = b->id;
                PolygonShape *tile = (PolygonShape*)b->ps;
                c.norm = CalcNormal(tile->getVerts());
                c.pos = LinePlaneIntersect(c.norm, tile->getVerts()[0], a->pos, c.norm);
                
                collisions.push_back(c);
            }
        }
    }
    
}
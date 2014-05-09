//
//  PhysicsUtil.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-08.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PhysicsUtil.h"


using namespace glm;


vec2 stripAxes(vec3 v, int nr){

    if (nr == 0){
        return vec2(v[1],v[2]);
    }else if (nr == 1){
        return vec2(v[0],v[2]);
    }else {
       return vec2(v[0],v[1]);
    }

    
}

glm::vec3 calcNormal(glm::vec3 a, glm::vec3 b, glm::vec3 c) {

    
    b = b - a;
    c = c - a;
    
    glm::vec3 norm = glm::cross(b, c);
    norm = glm::normalize(norm);

    return norm;
    
}

bool d0(float a, float b){
    return fabs(a - b) < 0.00001;
}


// Discounts y axis
bool pointOnLineSeg(glm::vec3 v1, glm::vec3 v2, glm::vec3 point) {
    v1 -= point;
    v2 -= point;
    if (v2.x == v1.x)return (v2.z*v1.z < 0 && v2.x > 0);
    float slope = (v2-v1).z / (v2-v1).x;
    float m = v1.y - slope * v1.x;
    return (m*slope < 0);
}

bool pointInPoly2D(std::vector<glm::vec2> verts, glm::vec2 point){
    
    std::vector<vec2> transVerts;
    
    for (int i = 0; i<verts.size(); i++) {
        transVerts.push_back(verts[i]-point);
    }
    transVerts.push_back(transVerts[0]);
    
    int intersects = 0;
    
    for (int i = 0 ; i< verts.size() -1 ; i++){
        
        vec2 v1 = transVerts[i];
        vec2 v2 = transVerts[i+1];
    
        if (v1.y * v2.y < 0){
            if (v1.x > 0.0 && v2.x > 0.0){
                intersects++;
            }else if (v1.x * v2.x < 0.0){
                if (fabsf(v1.y / v1.x) < fabsf((v2.y - v1.y)/(v2.x - v1.x))){
                    intersects++;
                }
            }
        }
    }
    
    return intersects % 2;
}

float distanceFromLine(glm::vec3 a,glm::vec3 b,glm::vec3 point){
    
    return length(cross(b-a,a-b))/length(b-a);
    
}


bool pointInPoly3D(std::vector<glm::vec3> verts, glm::vec3 point) {
    
    if (verts.size() < 2){
        throw std::runtime_error("You need at least two points dumbass");
    }
    
    if (verts.size() == 2){
        float dist = distanceFromLine(verts[0],verts[1],point);
        return d0(0.0,dist);
    }
    
    vec3 norm = calcNormal(verts[0],verts[1],verts[2]);
    
    float m = 0.0;
    float rm = 0;
    for (int i = 0; i<3 ; i++){
        if (m < norm[i]){
            rm = i;
        }
    }
    
    std::vector<glm::vec2> vert2D;
    
    for (int i = 0 ; i< verts.size() ; i++){
        vec2 tmp = stripAxes(verts[i],rm);
        
        vert2D.push_back(tmp);
    }
    
    vec2 point2D = stripAxes(point, rm);
    return pointInPoly2D(vert2D, point2D);
}


float distanceFromPlane(glm::vec3 pointOnPlane, glm::vec3 planeNormal, glm::vec3 point){
    
    return dot((point - pointOnPlane),planeNormal);
    
    
}
//
//  Cup.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Cup.h"

#include "PolygonShape.h"
#include "Mesh.h"

#include "PhysicsUtil.h"

Cup::Cup(glm::vec3 pos, vec3 normal, float size, int idd): GameObject::GameObject(idd){
    
    setIdentifier("CUP");
    pos += glm::vec3(0,0,0);
    
    glm::vec3 n = normal;
    glm::vec3 p1;
    
    if (n.y != 0.0f){
        p1 = glm::vec3(1.0,-(n.x + n.z)/n.y,1.0);
    }else if (n.z != 0.0f){
        p1 = glm::vec3(1.0,1.0,-(n.x + n.y)/n.z);
    }else if (n.x != 0.0f){
        p1 = glm::vec3(0,1.0,1.0);
    }else {
        std::cout << "Cup without normal setting something else";
        p1 = glm::vec3(0,1.0,1.0);
    }
    
    p1 = glm::normalize(p1);
    glm::vec3 p2 = glm::cross(n, p1);
    p2 = glm::normalize(p2);
    
    vector<glm::vec3> cupVerts;
    
    
    for (float i = 0; i<= 2*M_PI ; i+= M_PI/5.0){
        
        glm::vec3 na = p1  * cosf(i);
        glm::vec3 nb = p2  * sinf(i);
        
        glm::vec3 v = (na + nb) * size;
        
        cupVerts.push_back(v);
        
    }

    
    PhysicShape *pss = new PolygonShape(cupVerts);
    
    physicsObject = new PObject(idd,pss,pos, true);
    
    vector<vec3> normals;
    
    for (int i = 0; i<cupVerts.size(); i++) {
        normals.push_back(n);
    }
    
    mesh = new Mesh("default.vs","black.fsh", &cupVerts,&normals,GL_TRIANGLE_FAN);
    
}

void Cup::collidedWith(GameObject *other, vec3 hitNormal, vec3 pos){
    
    printf("yes this is dog %d\n",this->objectId);
    
}

std::string Cup::name(){
    return "Cup";
}


///////
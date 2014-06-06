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
    
    glm::vec3 n = normal;
    
    glm::vec3 p1 = glm::vec3(1.0,1.0,-(n.x + n.y)/n.z);
    
    p1 = glm::normalize(p1);
    glm::vec3 p2 = glm::cross(n, p1);
    p2 = glm::normalize(p2);
    
    vector<glm::vec3> cupVerts;
    
    float r = size;
    
    for (float i = 0; i<= 2*M_PI ; i+= M_PI/10){
        
        glm::vec3 na = p1 * r * cosf(i);
        glm::vec3 nb = p2 * r * sinf(i);
        
        glm::vec3 v = pos + na + nb;
        
        cupVerts.push_back(v);
        
    }
    
    vector<glm::vec3> verts = cupVerts;

    
    PhysicShape *pss = new PolygonShape(verts);
    
    physicsObject = new PObject(idd,pss,vec3(0.0,0.0,0.0), true);
    
    vector<vec3> normals;
    
    for (int i = 0; i<verts.size(); i++) {
        normals.push_back(n);
    }
    
    mesh = new Mesh("default.vs","red.fsh", &verts,&normals,GL_TRIANGLE_FAN);
    
}


///////
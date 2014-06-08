//
//  Arrow.cpp
//  Engine
//
//  Created by Mats Allen on 6/7/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//


#include "PolygonShape.h"

#include "PhysicsUtil.h"

#include "Mesh.h"

#include "Arrow.h"

Arrow::Arrow(glm::vec3 pos, int idd): GameObject::GameObject(idd){
    float size = 0.1;
    setIdentifier("ARROW");
    
    vector<glm::vec3> verts;
    
    verts.push_back(vec3(-size, 0.0, -size));
    verts.push_back(vec3(+size, 0.0, -size));
    verts.push_back(vec3(+size, 0.0, +size));
    
    verts.push_back(vec3(-size, 0.0, -size));
    verts.push_back(vec3(-size, 0.0, +size));
    verts.push_back(vec3(+size, 0.0, +size));
    
    verts.push_back(vec3(-2*size, 0.0, +size));
    verts.push_back(vec3(0.0,     0.0, 2*size));
    verts.push_back(vec3(+2*size, 0.0, +size));
    
    
    PhysicShape *pss = new PolygonShape(verts);
    
    physicsObject = new PObject(idd, pss, pos, true);
    
    vec3 n = calcNormal(verts[0], verts[1], verts[2]);
    
    vector<vec3> normal;
    
    for (int i = 0; i<verts.size(); i++) {
        normal.push_back(n);
    }
    
    mesh = new Mesh("default.vs","blue.fsh", &verts,&normal,GL_TRIANGLES);
    
}


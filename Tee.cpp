//
//  Tee.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Tee.h"

#include "PolygonShape.h"

#include "PhysicsUtil.h"

#include "Mesh.h"

Tee::Tee(glm::vec3 pos, float size, int idd): GameObject::GameObject(idd){
    
    vector<glm::vec3> verts;
    
    verts.push_back(pos + vec3(-size, 0.0, -size));
    verts.push_back(pos + vec3(-size, 0.0, +size));
    verts.push_back(pos + vec3(size, 0.0, size));
    verts.push_back(pos + vec3(size, 0.0, -size));
    
    PhysicShape *pss = new PolygonShape(verts);
    
    physicsObject = new PObject(idd,pss,vec3(0.0,0.0,0.0), true);
    
    vec3 n = calcNormal(verts[0], verts[1], verts[2]);
    
    vector<vec3> normal;
    
    for (int i = 0; i<verts.size(); i++) {
        normal.push_back(n);
    }
    
    mesh = new Mesh("default.vs","blue.fsh", &verts,&normal,GL_TRIANGLE_FAN);
    
}
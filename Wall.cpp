//
//  Wall.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Wall.h"

#include "PolygonShape.h"

#include "PhysicsUtil.h"

#include "Mesh.h"

Wall::Wall(vec3 a, vec3 b, float height , int idd): GameObject::GameObject(idd){
    
    setIdentifier("WALL");
    
    vector<vec3> verts;
    
    verts.push_back(a);
    verts.push_back(a + vec3(0.0, height, 0.0));
    verts.push_back(b + vec3(0.0, height, 0.0));
    verts.push_back(b);
    
    PhysicShape *pss = new PolygonShape(verts);
    physicsObject = new PObject(idd,pss,vec3(0.0,0.0,0.0), true);
        
    vec3 n = calcNormal(verts[0], verts[1], verts[2]);
    
    vector<vec3> normal;
    
    for (int i = 0; i<verts.size(); i++) {
        normal.push_back(n);
    }
    
    mesh = new Mesh("default.vs","red.fsh", &verts,&normal,GL_TRIANGLE_FAN);
    
    
}
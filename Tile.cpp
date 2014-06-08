//
//  Tile.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Tile.h"

#include "PolygonShape.h"

#include "PhysicsUtil.h"

Tile::Tile(vector<glm::vec3> verts, int idd): GameObject::GameObject(idd){
    
    PhysicShape *pss = new PolygonShape(verts);
    
    physicsObject = new PObject(idd,pss,vec3(0.0,0.0,0.0), true);
    
    vec3 n = calcNormal(verts[0], verts[1], verts[2]);
    
    vector<vec3> normal;
    
    for (int i = 0; i<verts.size(); i++) {
        normal.push_back(n);
    }
    
    mesh = new Mesh("default.vs","green.fsh", &verts,&normal,GL_TRIANGLE_FAN);
    
}


std::string Tile::name(){
    return "Tile";
}
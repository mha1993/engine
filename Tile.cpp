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
    
    setIdentifier("TILE");
    
    PhysicShape *pss = new PolygonShape(verts);
    
    physicsObject = new PObject(idd,pss,vec3(0.0,0.0,0.0), true);
    
    vec3 n = calcNormal(verts[0], verts[1], verts[2]);
    
    vector<vec3> normal;
    
    for (int i = 0; i<verts.size(); i++) {
        normal.push_back(n);
    }
    
    mesh = new Mesh("default.vs","white.fsh", &verts,&normal,GL_TRIANGLE_FAN);
    
}


std::string Tile::name(){
    return "Tile";
}

void Tile::addNeighbor(int idd, int edge) {
    neighbors.push_back(pair<int, int>(idd, edge));
}

vector<pair<int, int>> Tile::getNeighbors() {
    return neighbors;
}

pair<vec3, vec3> Tile::getEdge(int e) {
    vector<vec3> verts = ((PolygonShape*)physicsObject->ps)->getVerts();
    return pair<vec3, vec3>(verts[e], verts[(e+1)%verts.size()]);
}
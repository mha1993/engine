//
//  Hole.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Hole.h"

#include "Tile.h"
#include "Cup.h"
#include "Wall.h"
#include "Ball.h"
#include "Tee.h"

Hole::Hole(WindowManager *wm) : BaseLevel(wm){}

void Hole::setName(string name){
    this->name = name;
}
void Hole::addTile(vector<string> line, int lineid){
    
    if (line.size() < 3) {
        std::cout << "ERROR: incomplete tile on line " << lineid+1;
        exit(EXIT_FAILURE);
    }else if (line.size() != 3 + atoi(line[2].c_str())*3 + atoi(line[2].c_str())){
        std::cout << "ERROR: invalid tile on line " << lineid+1;
        exit(EXIT_FAILURE);
    }
    int tileId = atoi(line[1].c_str());
    int numberOfVertices = atoi(line[2].c_str());
    
    vector<glm::vec3> verts;
    
    for (int i = 0; i<3*numberOfVertices; i+=3) {
        
        glm::vec3 v = glm::vec3(atof(line[i+3+0].c_str()),atof(line[i+3+1].c_str()),atof(line[i+3+2].c_str()));
        verts.push_back(v);
    }
    
    this->addObject(new Tile(verts,tileId));
    
    for (int i = 0; i<numberOfVertices ; i++){
        int pos = 3+3*numberOfVertices + i;
        int e = atoi(line[pos].c_str());
        if (e == 0){
            vector<glm::vec3> lineVertices;
            int v2 = i+1 < numberOfVertices ? i+1 : 0;
            
            this->addWall(verts[i], verts[v2]);
        }
    }
}
void Hole::addTee(vector<string> line, int lineid){
    
    if (line.size() != 5) {
        std::cout << "ERROR: invalid tee on line " << lineid+1;
        exit(EXIT_FAILURE);
    }
    glm::vec3 loc = glm::vec3(atof(line[2].c_str()),atof(line[3].c_str()),atof(line[4].c_str()));
    
}

void Hole::addCup(vector<string> line, int lineid){
    
    if (line.size() != 5) {
        std::cout << "ERROR: invalid cup on line " << lineid+1;
        exit(EXIT_FAILURE);
    }
    glm::vec3 loc = glm::vec3(atof(line[2].c_str()),atof(line[3].c_str()),atof(line[4].c_str()));
    
    Tile *t = (Tile *) this->getObject(atof(line[1].c_str()));
    
    t->getPhysicsObject();
    
}



static unsigned int wallids = 100000;

void Hole::addWall(vec3 a, vec3 b){
    
    this->addObject(new Wall(a,b,0.1f,wallids++));
    
}

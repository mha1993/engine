//
//  Hole.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Hole.h"


static unsigned int extraIds = 100000;

Hole::Hole(WindowManager *wm, HudRenderer * hd) : BaseLevel(wm, hd){}

void Hole::setName(string name){
    this->name = name;
}

void Hole::addLine(vector<string> line){
    lines.push_back(line);
}

void Hole::setup(){
    
    for (int i = 0; i<lines.size(); i++){
        vector<string> line = lines[i];
        
        string lineType = line[0];
        
        if (lineType.compare(PAR) == 0){
            setPar(line);
        }else if (lineType.compare(NAME) == 0){
            setName(TextUtils::myconcat(line," ",1));
        }else if (lineType.compare(TILE) == 0){
            addTile(line, i);
        }else if (lineType.compare(TEE) == 0){
            addTee(line, i);
        }else if (lineType.compare(CUP) == 0){
            addCup(line, i);
        }else{
            std::cout << "ERROR: incomplete word "<< lineType << endl;
            exit(EXIT_FAILURE);        }
    }
}

void Hole::setPar(vector<string> line){
    if (line.size() < 2) {
        std::cout << "ERROR: incomplete tile on line " << -10+1;
        exit(EXIT_FAILURE);
    }
    par = atoi(line[1].c_str());
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
    loc += vec3(0.0, 0.001, 0.0);
    tee = new Tee(loc, 0.1, extraIds++);
    this->addObject(tee);
    
}


void Hole::addArrow(int lineid){
    glm::vec3 loc = ball->getPhysicsObject()->pos + vec3(0,0.2,0);
    arrow = new Arrow(loc, extraIds++);
    this->addObject(arrow);
}


void Hole::addCup(vector<string> line, int lineid){
    
    if (line.size() != 5) {
        std::cout << "ERROR: invalid cup on line " << lineid+1;
        exit(EXIT_FAILURE);
    }
    glm::vec3 loc = glm::vec3(atof(line[2].c_str()),atof(line[3].c_str()),atof(line[4].c_str()));
    
    int tileId = atof(line[1].c_str());
    
    Tile *t             = (Tile *)          this->getObject(tileId);
    
    if (t == nullptr){
        std::cout << "ERROR: no cup to place tile on nr:" << tileId << " on liner:"  << lineid+1;
        exit(EXIT_FAILURE);
    }
    
    PObject *pobj       = (PObject * )      t->getPhysicsObject();
    PolygonShape *dsa   = (PolygonShape *)  pobj->ps;
    vector<vec3> verts  =                   dsa->getVerts();
    vec3 normal         =                   calcNormal(verts[0],verts[1],verts[2]);
    
    loc += vec3(0.0, 0.001, 0.0);
    cup = new Cup(loc , normal, 0.07,extraIds++);
    this->addObject(cup);
}


void Hole::addWall(vec3 a, vec3 b){
    
    this->addObject(new Wall(a,b,0.1f,extraIds++));
    
}



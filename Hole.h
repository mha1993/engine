//
//  Hole.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Hole__
#define __Engine__Hole__

#include <iostream>

#include "BaseLevel.h"
#include <string>

#include "glm.hpp"
#include "Tile.h"
#include "Cup.h"
#include "Wall.h"
#include "Ball.h"
#include "Tee.h"
#include "PolygonShape.h"
#include "PhysicsUtil.h"
#include "TextUtils.h"

#define PAR "par"
#define NAME "name"
#define TILE "tile"
#define TEE "tee"
#define CUP "cup"


using namespace glm;
using namespace std;

class Hole : public BaseLevel{
    
    string name;
    vector<vector<string>> lines;
    
    int par;
    
public:
    Hole(WindowManager *wm);
    void setName(string name);
    void addTile(vector<string> thing, int lineid);
    void addCup(vector<string> thing, int lineid);
    void addTee(vector<string> thing, int lineid);
    
    void addLine(vector<string> line);
    void setPar(vector<string> i);
    void setup();
    
    void run();
    
private:
    void addWall(vec3 a, vec3 b);
    
};


#endif /* defined(__Engine__Hole__) */

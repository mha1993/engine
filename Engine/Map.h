//
//  Map.h
//  GameEngine
//
//  Created by Jakob Folkesson on 2014-04-15.
//  Copyright (c) 2014 Jakob Folkesson. All rights reserved.
//

#ifndef __GameEngine__Map__
#define __GameEngine__Map__

#include <iostream>
#include <vector>
#include <string>
#include "glm.hpp"

#include "Object.h"
#include "TileRenderer.h"
#include "Program.h"
#include "Shader.h"
#include "PhysicsEngine.h"
#include "Camera.h"



using namespace std;
class Map {
    vector<Renderer *> renderers;
    vector<Object*> objects;
    vector<Object*> neighbors;
    vector<int> neighborIds;
    Program *tileProgram;
    Program *edgeProgram;
    PhysicsEngine *pe;
    
public:
    Map(string file);
    void render(tdogl::Camera *camera);
    
    
private:
    void processLine(vector<string> line, int lineNumber);
    void constructTileProgram();
    void constructEdgeProgram();
};

#endif /* defined(__GameEngine__Map__) */

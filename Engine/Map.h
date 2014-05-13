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

class ECamera;



using namespace std;
class Map {
    Object *mrBall;
    vector<Renderer *> renderers;
    vector<Object*> objects;
    vector<Object*> neighbors;
    vector<int> neighborIds;
    Program *tileProgram;
    Program *edgeProgram;
    PhysicsEngine *pe;
    float ballRadius = .09;
    Object *tee;
    
public:
    Map(string file);
    void render(tdogl::Camera *camera);
    vector<ECamera *> getCameras(float aspectRatio);
    
private:
    void processLine(vector<string> line, int lineNumber);
    void constructTileProgram();
    void constructEdgeProgram();
};

#endif /* defined(__GameEngine__Map__) */

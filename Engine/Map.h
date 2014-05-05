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
#include "Program.h"
#include "Shader.h"
#include "Camera.h"


using namespace std;

struct Tile {
    int id;
    int numberOfVertices;
    Object *object;
    
    void render() {
        object->render();
    }
};

struct Tee {
    glm::vec3 loc;
};

struct Cup {
    glm::vec3 loc;
};

struct Edge {
    Object *object;
    
    void render() {
        object->render();
    }
};

class Map {
    vector<Tile> tiles;
    vector<Edge> edges;
    vector<Object*> neighbors;
    vector<int> neighborIds;
    Cup cup;
    Tee tee;
    Program *tileProgram;
    Program *edgeProgram;
    
public:
    Map(string file);
    void render(tdogl::Camera *camera);
    
    
private:
    void processLine(vector<string> line, int lineNumber);
    void constructTileProgram();
    void constructEdgeProgram();
};

#endif /* defined(__GameEngine__Map__) */

//
//  Map.cpp
//  GameEngine
//
//  Created by Jakob Folkesson on 2014-04-15.
//  Copyright (c) 2014 Jakob Folkesson. All rights reserved.
//

#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>

#include "Map.h"

#define TILE "tile"
#define TEE "tee"
#define CUP "cup"



void Map::render(tdogl::Camera *camera) {
    for (int i=0; i<tiles.size(); i++) {
        tiles[i].object->setCameraMatrix(camera->Camera::matrix());
        tiles[i].render();
    }
    for (int i=0; i<edges.size(); i++) {
        edges[i].object->setCameraMatrix(camera->Camera::matrix());
        edges[i].render();
    }
}

void Map::constructTileProgram() {
    vector<Shader> shaders;
    Shader *vertShader = new Shader::Shader("shader.vsh", GL_VERTEX_SHADER);
    Shader *fragShader = new Shader::Shader("green.fsh", GL_FRAGMENT_SHADER);
    
    shaders.push_back(*vertShader);
    shaders.push_back(*fragShader);
    
    tileProgram = new Program::Program(shaders);
}

void Map::constructEdgeProgram() {
    vector<Shader> shaders;
    Shader *vertShader = new Shader::Shader("shader.vsh", GL_VERTEX_SHADER);
    Shader *fragShader = new Shader::Shader("red.fsh", GL_FRAGMENT_SHADER);
    
    shaders.push_back(*vertShader);
    shaders.push_back(*fragShader);
    
    edgeProgram = new Program::Program(shaders);
}

void Map::processLine(vector<string> line, int lineNumber) {
    if (line[0].compare(TILE) == 0){
        if (line.size() < 3) {
            std::cout << "ERROR: incomplete tile on line " << lineNumber+1;
            exit(EXIT_FAILURE);
        }else if (line.size() != 3 + atoi(line[2].c_str())*3 + atoi(line[2].c_str())){
            std::cout << "ERROR: invalid tile on line " << lineNumber+1;
            exit(EXIT_FAILURE);
        }
        Tile tile;
        tile.id = atoi(line[1].c_str());
        tile.numberOfVertices = atoi(line[2].c_str());
        tile.object = new Object::Object();
        GLfloat vertices[tile.numberOfVertices * 3];
        for (int i = 0; i<3*tile.numberOfVertices; i+=3) {
            float x = atof(line[3+i].c_str());
            float y = atof(line[3+i+1].c_str());
            float z = atof(line[3+i+2].c_str());
            vertices[i] = x;
            vertices[i+1] = y;
            vertices[i+2] = z;
        }
        
        tile.object->addProgram(tileProgram);
        tile.object->setDrawMethod(GL_TRIANGLE_FAN);
        tile.object->Object::addVertices(tile.numberOfVertices, vertices);
        for (int i = 0; i<tile.numberOfVertices ; i++){
            int pos = 3+3*tile.numberOfVertices + i;
            int e = atoi(line[pos].c_str());
            if (e == 0){
                
                GLfloat vertices[6];
                glm::vec3 vert1 = tile.object->getVertex(i);
                glm::vec3 vert2 = i+1 < tile.object->getNumberOfVertices() ? tile.object->getVertex(i+1) : tile.object->getVertex(0);
                vertices[0] = vert1.x;
                vertices[1] = vert1.y;
                vertices[2] = vert1.z;
                vertices[3] = vert2.x;
                vertices[4] = vert2.y;
                vertices[5] = vert2.z;
                
                
                Edge e;
                e.object = new Object();
                e.object->Object::addProgram(edgeProgram);
                e.object->Object::setDrawMethod(GL_LINES);
                e.object->Object::addVertices(2, vertices);
                edges.push_back(e);
            }
        }
        
        tiles.push_back(tile);
     /****** TEES AND CUPS ****
    }else if (line[0].compare(TEE) == 0){
        if (line.size() != 5) {
            std::cout << "ERROR: invalid tee on line " << lineNumber+1;
            exit(EXIT_FAILURE);
        }
        tee.loc = glm::vec3(atof(line[2].c_str()),
                            atof(line[3].c_str()),
                            atof(line[4].c_str()));
    }else if (line[0].compare(CUP) == 0){
        if (line.size() != 5) {
            std::cout << "ERROR: invalid cup on line " << lineNumber+1;
            exit(EXIT_FAILURE);
        }
        cup.loc = glm::vec3(atof(line[2].c_str()),
                            atof(line[3].c_str()),
                            atof(line[4].c_str()));
      ***********************/
    }else{
    
        std::cout << "Warning: invalid name: " + line[0] << endl;
    
    }
    
}


Map::Map(string file) {
    constructTileProgram();
    constructEdgeProgram();

    string line;
    istringstream f((file));
        int lineNumber = 0;
        while ( getline (f,line) )
        {
            vector<string> vec;
            istringstream iss((line));
            copy(istream_iterator<string>(iss),
                 istream_iterator<string>(),
                 back_inserter(vec));
            processLine(vec, lineNumber);
            lineNumber++;
        }
}
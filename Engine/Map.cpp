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

#include "SphereRenderer.h"

#include "Map.h"

#define TILE "tile"
#define TEE "tee"
#define CUP "cup"



void Map::render(tdogl::Camera *camera) {
    
    glm::mat4 *cam;
    glm::mat4 bla = camera->Camera::matrix();
    cam = &bla;
    
    for (int i=0; i<renderers.size(); i++) {
        renderers[i]->setCameraMatrix(cam);
        renderers[i]->render();
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
        int tileId = atoi(line[1].c_str());
        int numberOfVertices = atoi(line[2].c_str());
        
        Renderer *tileRenderer = new TileRenderer;
        tileRenderer->addProgram(tileProgram);
        Object *tileObject = new Object::Object();
        
        tileObject->setRenderer(tileRenderer);
        tileRenderer->setObject(tileObject);
        
        GLfloat *vertices = new GLfloat[numberOfVertices * 3];
        
        for (int i = 0; i<3*numberOfVertices; i++) {
            vertices[i] = atof(line[i+3].c_str());
        }
        
        tileRenderer->addProgram(tileProgram);
        tileRenderer->setDrawMethod(GL_TRIANGLE_FAN);
        tileObject->setNRVertAndVertex(numberOfVertices, vertices);
        
        for (int i = 0; i<numberOfVertices ; i++){
            int pos = 3+3*numberOfVertices + i;
            int e = atoi(line[pos].c_str());
            if (e == 0){
                
                GLfloat *lineVertices = new GLfloat[6];
                int v2 = i+1 < numberOfVertices ? i+1 : 0;
                
                
                lineVertices[0] = vertices[i*3+0];
                lineVertices[1] = vertices[i*3+1];
                lineVertices[2] = vertices[i*3+2];
                
                lineVertices[3] = vertices[v2*3+0];
                lineVertices[4] = vertices[v2*3+1];
                lineVertices[5] = vertices[v2*3+2];
                
                Object *edgeObject = new Object;
                Renderer *edgeRenderer = new Renderer;
                
                edgeObject->setRenderer(edgeRenderer);
                edgeRenderer->setObject(edgeObject);
                
                edgeRenderer->addProgram(edgeProgram);
                edgeRenderer->setDrawMethod(GL_LINES);
                
                edgeObject->setNRVertAndVertex(2, lineVertices);
                
                renderers.push_back(edgeRenderer);
            }
        }
        
        renderers.push_back(tileRenderer);
        /****** TEES AND CUPS *****/
    }else if (line[0].compare(TEE) == 0){
       
        if (line.size() != 5) {
            std::cout << "ERROR: invalid tee on line " << lineNumber+1;
            exit(EXIT_FAILURE);
        }
        glm::vec3 loc = glm::vec3(atof(line[2].c_str()),atof(line[3].c_str()),atof(line[4].c_str()));
        
        
        loc = loc + glm::vec3(0,.001,0);
        GLfloat *vertices = new GLfloat[4 * 3];
        
        
        
        vertices[0] = loc.x -.1;
        vertices[1] = loc.y;
        vertices[2] = loc.z -.1;
        
        vertices[3] = loc.x -.1;
        vertices[4] = loc.y;
        vertices[5] = loc.z +.1;
        
        vertices[6] = loc.x +.1;
        vertices[7] = loc.y;
        vertices[8] = loc.z +.1;
        
        vertices[9] = loc.x +.1;
        vertices[10] = loc.y;
        vertices[11] = loc.z -.1;
        
        Object *tea = new Object;
        
        TileRenderer *teaRenderer = new TileRenderer;
        
        teaRenderer->addProgram(Program::TeaProgram());
        
        tea->setRenderer(teaRenderer);
        teaRenderer->setObject(tea);
        
        tea->setNRVertAndVertex(4, vertices);

        renderers.push_back(teaRenderer);
    
    }else if (line[0].compare(CUP) == 0){
        
        if (line.size() != 5) {
            std::cout << "ERROR: invalid cup on line " << lineNumber+1;
            exit(EXIT_FAILURE);
        }
        glm::vec3 loc = glm::vec3(atof(line[2].c_str()),atof(line[3].c_str()),atof(line[4].c_str()));
        
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
    Renderer *sphere = new SphereRenderer(10.0);
    
    renderers.push_back(sphere);
    
}
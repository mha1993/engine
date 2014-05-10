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

#include <glm/gtc/matrix_transform.hpp>

#include "PhysicsUtil.h"
#include "PhysicsPlane.h"

glm::vec3 teeLoc;


void Map::render(tdogl::Camera *camera) {
    
    glm::mat4 *cam;
    glm::mat4 bla = camera->Camera::matrix();
    cam = &bla;
    
    pe->tick(.1);
    
    for (int i=0; i<renderers.size(); i++) {
        renderers[i]->setCameraMatrix(cam);
        
        renderers[i]->render();
    }
    
}



void Map::constructTileProgram() {
    /*
    vector<Shader> shaders;
    Shader *vertShader = new Shader::Shader("shader.vsh", GL_VERTEX_SHADER);
    Shader *fragShader = new Shader::Shader("green.fsh", GL_FRAGMENT_SHADER);
    
    shaders.push_back(*vertShader);
    shaders.push_back(*fragShader);
    
    tileProgram = new Program::Program(shaders);
     */
}



void Map::constructEdgeProgram() {
    /*
    vector<Shader> shaders;
    Shader *vertShader = new Shader::Shader("shader.vsh", GL_VERTEX_SHADER);
    Shader *fragShader = new Shader::Shader("red.fsh", GL_FRAGMENT_SHADER);
    
    shaders.push_back(*vertShader);
    shaders.push_back(*fragShader);
    
    edgeProgram = new Program::Program(shaders);
     */
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
        //tileRenderer->addProgram(tileProgram);
        Object *tileObject = new Object::Object();
        
        tileObject->setRenderer(tileRenderer);
        tileRenderer->setObject(tileObject);
        
        
        vector<glm::vec3> verts;
        
        for (int i = 0; i<3*numberOfVertices; i+=3) {
            
            glm::vec3 v = glm::vec3(atof(line[i+3+0].c_str()),atof(line[i+3+1].c_str()),atof(line[i+3+2].c_str()));
            
            verts.push_back(v);
        }
        
        glm::vec3 tileNormal = -calcNormal(verts[0],verts[1],verts[2]);
        
        PhysicsPlane *tilePhysics = new PhysicsPlane(verts);
        
        tilePhysics->addNormal(tileNormal);
        pe->addPlane(tilePhysics);
        
        
        //tileRenderer->addProgram(tileProgram);
        //tileRenderer->setDrawMethod(GL_TRIANGLE_FAN);
        tileObject->setNRVertAndVertex(verts);
        
        for (int i = 0; i<numberOfVertices ; i++){
            int pos = 3+3*numberOfVertices + i;
            int e = atoi(line[pos].c_str());
            if (e == 0){
                
                vector<glm::vec3> lineVertices;
                int v2 = i+1 < numberOfVertices ? i+1 : 0;
                
                
                lineVertices.push_back(verts[i]);
                lineVertices.push_back(verts[v2]);
                
                Object *edgeObject = new Object;
                Renderer *edgeRenderer = new Renderer;
                
                edgeObject->setRenderer(edgeRenderer);
                edgeRenderer->setObject(edgeObject);
                
                edgeRenderer->addProgram( Program::fetchProgram("shader.vsh", "red.fsh") );
                edgeRenderer->setDrawMethod(GL_LINES);
                
                edgeObject->setNRVertAndVertex(lineVertices);
                
                PhysicsPlane *pp = new PhysicsPlane(lineVertices);
                
                
                int v3 = i+2 < numberOfVertices ? i+2 : 1;
                glm::vec3 edgeNormal = calcNormal(lineVertices[0], lineVertices[1], lineVertices[0] - tileNormal);
                
                pp->addNormal(edgeNormal);
                
                pe->addPlane(pp);
                
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
        
        teeLoc = loc;
        loc = loc + glm::vec3(0,.001,0);
        vector<glm::vec3> teeVert;
        
        
        teeVert.push_back(loc + glm::vec3(-.1,0,-.1));
        teeVert.push_back(loc + glm::vec3(-.1,0,+.1));
        teeVert.push_back(loc + glm::vec3(+.1,0,+.1));
        teeVert.push_back(loc + glm::vec3(+.1,0,-.1));

        
        tee = new Object;
        
        TileRenderer *teeRenderer = new TileRenderer;
        
        tee->setRenderer(teeRenderer);
        teeRenderer->setObject(tee);
        
        
        teeRenderer->addProgram(Program::fetchProgram("shader.vsh", "blue.fsh"));
        
        tee->setNRVertAndVertex(teeVert);

        renderers.push_back(teeRenderer);
    
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
    
    pe = new PhysicsEngine();
    
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
    
    float ballRadius = .09;
    
    
    Object *sphere = new Object::Object();
    PhysicsObject *ballPhysics = new PhysicsObject(ballRadius);
    sphere->setPhysics(ballPhysics);
    Renderer *sphereRenderer = new SphereRenderer();
    sphereRenderer->setObject(sphere);
    
    sphere->Object::setRenderer(sphereRenderer);
    pe->addMovableObject(ballPhysics);
    ballPhysics->setVelocity(glm::vec3(1.0,0,0.41));
    //sphere->getPhysics()->scale(glm::scale(glm::mat4(), glm::vec3(.1,.1,.1)));
    ballPhysics->setPosition(teeLoc);
    ballPhysics->offsetPosition(glm::vec3(0,ballRadius,0));
    
    renderers.push_back(sphereRenderer);
    
}
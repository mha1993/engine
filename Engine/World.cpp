//
//  World.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//




#include "World.h"
#include "Shader.h"
#include "Program.h"
#include "Object.h"
#include "Map.h"
#include "FileReader.h"

#include <GL/glfw.h>


#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400


void World::loadMap() {
    currCamera = 0;
    FileReader *fr = new FileReader::FileReader();
    map = new Map::Map(fr->readFile("maps/hole.02.db"));
    cameras = map->getCameras(WINDOW_WIDTH/WINDOW_HEIGHT);
}

void World::renderScene() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    map->render(cameras[currCamera]);
    glfwSwapBuffers();
}

// update the scene based on the time elapsed since last update
void World::Update(float secondsElapsed) {

    
    if (glfwGetKey('C')){
        printf("dsadsadsadadsdsaa");
        currCamera = ++currCamera % cameras.size();
    }
    
    cameras[currCamera]->update(secondsElapsed);
    
}

void World::init() {
    // initialise GLFW
    if(!glfwInit())
        throw std::runtime_error("glfwInit failed");
    
    // open a window with GLFW
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    if(!glfwOpenWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 8, 8, 8, 8, 24, 0, GLFW_WINDOW))
        throw std::runtime_error("glfwOpenWindow failed. Can your hardware handle OpenGL 3.2?");
    
    // initialise GLEW
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if(glewInit() != GLEW_OK)
        throw std::runtime_error("glewInit failed");
    
    // print out some info about the graphics drivers
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    cout << endl;
    
    // make sure OpenGL version 3.2 API is available
    if(!GLEW_VERSION_3_2)
        throw std::runtime_error("OpenGL 3.2 API is not available.");
    
    // create buffer and fill it with the points of the triangle
    loadMap();
    
    
    // run while the window is open
    double lastTime = glfwGetTime();
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    
    while(glfwGetWindowParam(GLFW_OPENED)){
        double thisTime = glfwGetTime();
        Update(thisTime - lastTime);
        lastTime = thisTime;
        
        renderScene();
        
        // check for errors
        GLenum error = glGetError();
        while(error != GL_NO_ERROR) {
            std::cerr << endl << "OpenGL Error " << error << ": " << (const char*)gluErrorString(error) << std::endl;
            error = glGetError();
        }
        
        //exit program if escape key is pressed
        if(glfwGetKey(GLFW_KEY_ESC))
            glfwCloseWindow();
    }
    
    // clean up and exit
    glfwTerminate();
	
}
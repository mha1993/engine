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

#include <OpenGL/gl3.h>
#include <GL/glfw.h>


#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400


void World::loadMap() {
    FileReader *fr = new FileReader::FileReader();
    map = new Map::Map(fr->readFile("maps/hole02.db"));
}

void World::renderScene() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    map->render(camera);
    glfwSwapBuffers();
}

// update the scene based on the time elapsed since last update
void World::Update(float secondsElapsed) {
    
    //move position of camera based on WASD keys, and XZ keys for up and down
    const float moveSpeed = 8.0; //units per second
    if(glfwGetKey('S')){
        camera->offsetPosition(secondsElapsed * moveSpeed * -camera->forward());
    } else if(glfwGetKey('W')){
        camera->offsetPosition(secondsElapsed * moveSpeed * camera->forward());
    }
    if(glfwGetKey('A')){
        camera->offsetPosition(secondsElapsed * moveSpeed * -camera->right());
    } else if(glfwGetKey('D')){
        camera->offsetPosition(secondsElapsed * moveSpeed * camera->right());
    }
    if(glfwGetKey('Z')){
        camera->offsetPosition(secondsElapsed * moveSpeed * -glm::vec3(0,1,0));
    } else if(glfwGetKey('X')){
        camera->offsetPosition(secondsElapsed * moveSpeed * glm::vec3(0,1,0));
    }
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
    if(!glfwOpenWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 8, 8, 8, 8, 0, 0, GLFW_WINDOW))
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
    
    camera = new tdogl::Camera::Camera();
    camera->setPosition(glm::vec3(0,5,5));
    camera->lookAt(glm::vec3(0,0,0));
    camera->setViewportAspectRatio(WINDOW_WIDTH/ WINDOW_HEIGHT);
    
    
    // run while the window is open
    double lastTime = glfwGetTime();
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
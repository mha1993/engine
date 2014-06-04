//
//  WindowManager.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-23.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "WindowManager.h"

#include "easylogging++.h"

#include <GL/glew.h>
#include <GL/glfw.h>


_INITIALIZE_EASYLOGGINGPP

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

using namespace std;

WindowManager::WindowManager(){
}


void WindowManager::beforeRender() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void WindowManager::afterRender(){
    glfwSwapBuffers();
}

void WindowManager::init() {
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
    LOG(INFO) << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    LOG(INFO) << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    LOG(INFO) << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    LOG(INFO) << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    LOG(INFO) << std::endl;
    
    // make sure OpenGL version 3.2 API is available
    if(!GLEW_VERSION_3_2)
        throw std::runtime_error("OpenGL 3.2 API is not available.");
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
}


string WindowManager::readString(){

    if (glfwGetKey(GLFW_KEY_TAB)){
    
        getline(cin, lastString);
        
    }
    
    return lastString;
}


bool WindowManager::quitRequest(){
    return glfwGetKey(GLFW_KEY_ESC);
}

void WindowManager::stop(){
    
    glfwCloseWindow();
    // clean up and exit
    glfwTerminate();
    
}

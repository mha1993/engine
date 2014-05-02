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

#include <OpenGL/gl3.h>
#include <GL/glfw.h>


#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400


// globals
GLuint gVAO = 0;
GLuint gVBO = 0;

vector<Object> objects;

Program *program = NULL;

// loads the vertex shader and fragment shader, and links them to make the global gProgram
static void loadShaders() {
    vector<Shader> shaders;
    Shader *vertShader = new Shader::Shader("shader.vsh", GL_VERTEX_SHADER);
    Shader *fragShader = new Shader::Shader("shader.fsh", GL_FRAGMENT_SHADER);
    
    shaders.push_back(*vertShader);
    shaders.push_back(*fragShader);
    
    program = new Program::Program(shaders);
    Object *object = new Object::Object();
    object->addProgram(program);
    
    objects.push_back(*object);
}

static void loadTriangle() {
    // Put the three triangle verticies into the VBO
    GLfloat vertexData[] = {
        //  X     Y     Z
        0.0f, 0.8f, 0.1f,
        -0.8f,-0.8f, 0.1f,
        0.8f,-0.8f, 0.1f,
    };
    int numVerts = 3;
    objects[0].Object::addVertices(numVerts, vertexData);
}

void renderScene() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    for (int i=0; i<objects.size(); i++) {
        objects[i].render();
    }
    
    glfwSwapBuffers();
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
    
    // make sure OpenGL version 3.2 API is available
    if(!GLEW_VERSION_3_2)
        throw std::runtime_error("OpenGL 3.2 API is not available.");
    
    // load vertex and fragment shaders into opengl
    loadShaders();
    
    // create buffer and fill it with the points of the triangle
    loadTriangle();
    
    // run while the window is open
    while(glfwGetWindowParam(GLFW_OPENED)){
        // draw one frame
        renderScene();
    }
    
    // clean up and exit
    glfwTerminate();
	
}
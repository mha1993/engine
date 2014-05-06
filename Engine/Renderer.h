//
//  Renderer.h
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Renderer__
#define __Engine__Renderer__

#include <iostream>
#include <vector>
#include "glm.hpp"
#include <GL/glew.h>

#include "Object.h"

#include "Program.h"

#define VERT_SHADER_NAME "vert"

#define NORM_SHADER_NAME "aVertexNormal"

using namespace std;

class Renderer {

public:
    void addProgram(Program *_program);
    
    //glm::vec3 getVertex(int i);
    int getNumberOfVertices();
    void setDrawMethod(GLuint _drawMethod);
    void setCameraMatrix(const glm::mat4 *matrix);
    void render();
    Renderer();
    
    void setObject(Object *o);
    
protected:
    Object *myObject;
    virtual void setVertexBuffer();
    void addNormals(int numVerts, GLfloat *_vertices);
    
    GLuint drawMethod;
    
    GLuint vbo;
    GLuint vao;
    
    
    Program *program;
    
    bool bufferIsSet = false;

    
};

#endif /* defined(__Engine__Renderer__) */

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

#include "Program.h"

using namespace std;

class Renderer {
    GLfloat *vertices;
    
    GLuint vbo;
    GLuint vao;
    Program *program;
    
public:
    void addProgram(Program *_program);
    void addVertices(int numVerts, GLfloat *_vertices);
    void render();
};

#endif /* defined(__Engine__Renderer__) */

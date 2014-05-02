//
//  Renderer.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Renderer.h"

void Renderer::addVertices(int numVerts, GLfloat _vertices[]) {
    vertices = _vertices;
    // make and bind the VAO
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    // make and bind the VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    // Put the three triangle verticies into the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * numVerts * 3, vertices, GL_STATIC_DRAW);
    
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(program->attrib("vert"));
    glVertexAttribPointer(program->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    // unbind the VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderer::addProgram(Program *_program) {
    program = _program;
}

void Renderer::render() {
    // bind the program (the shaders)
    glUseProgram(program->getProgram());
    
    // bind the VAO (the triangle)
    glBindVertexArray(vao);
    
    // draw the VAO
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    // unbind the VAO
    glBindVertexArray(0);
    
    // unbind the program
    glUseProgram(0);
}
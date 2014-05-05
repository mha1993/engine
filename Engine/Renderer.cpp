//
//  Renderer.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Renderer.h"
#include <glm/gtc/type_ptr.hpp>

void Renderer::setCameraMatrix(glm::mat4 matrix) {
    glUseProgram(program->getProgram());
    GLint uniform = glGetUniformLocation(program->getProgram(), "camera");
    if(uniform == -1)
        throw std::runtime_error(std::string("Program uniform not found: ") + "camera");
    glUniformMatrix4fv(uniform, 1, GL_FALSE, glm::value_ptr(matrix));
    glUseProgram(0);
}

void Renderer::addVertices(int numVerts, GLfloat *_vertices) {
    cout << "VERTICES:" << endl;
    cout << "\tnumber of verts: " << numVerts << endl;
    for (int i=0; i<numVerts*3; i++) {
        cout << "\t#" << i << ": " << _vertices[i] << endl;
    }
    numberOfVertices = numVerts;
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

glm::vec3 Renderer::getVertex(int i) {
    if (i > (numberOfVertices-1)) {
        cerr << "invalid vertex index!\n" << endl;
        return glm::vec3(0,0,0);
    } else {
        return glm::vec3(vertices[3*i], vertices[3*i+1], vertices[3*i+2]);
    }
}

int Renderer::getNumberOfVertices() {
    return numberOfVertices;
}

void Renderer::setDrawMethod(GLuint _drawMethod) {
    drawMethod = _drawMethod;
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
    glDrawArrays(drawMethod, 0, numberOfVertices*3);
    
    // unbind the VAO
    glBindVertexArray(0);
    
    // unbind the program
    glUseProgram(0);
}

Renderer::Renderer() {
    drawMethod = GL_TRIANGLES;
}
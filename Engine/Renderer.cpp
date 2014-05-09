//
//  Renderer.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Renderer.h"
#include <glm/gtc/type_ptr.hpp>

glm::mat4 Renderer::getModelMatrix() {
    return myObject->getModelMatrix();
}

void Renderer::setCameraMatrix(const glm::mat4 *matrix) {
    glUseProgram(program->getProgram());
    GLint uniform = glGetUniformLocation(program->getProgram(), "camera");
    if(uniform == -1)
        throw std::runtime_error(std::string("Program uniform not found: ") + "camera");
    glUniformMatrix4fv(uniform, 1, GL_FALSE, glm::value_ptr(*matrix));
    glUseProgram(0);
}

void Renderer::setModelMatrix() {
    glm::mat4 matrix = getModelMatrix();
    glUseProgram(program->getProgram());
    GLint uniform = glGetUniformLocation(program->getProgram(), "model");
    if(uniform == -1)
        throw std::runtime_error(std::string("Program uniform not found: ") + "model");
    glUniformMatrix4fv(uniform, 1, GL_FALSE, glm::value_ptr(matrix));
    glUseProgram(0);
}

void Renderer::setObject(Object *o){
    myObject = o;
}

void Renderer::setVertexBuffer() {
    
    int numVerts = myObject->getNrVert();

    
    vector<glm::vec3> vertices = myObject->getVertecis();
    
    // make and bind the VAO
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    // make and bind the VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    // Put the three triangle verticies into the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * numVerts, &vertices[0], GL_STATIC_DRAW);
    
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(program->attrib(VERT_SHADER_NAME));
    glVertexAttribPointer(program->attrib(VERT_SHADER_NAME), 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    // unbind the VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    
}

void Renderer::setDrawMethod(GLuint _drawMethod) {
    drawMethod = _drawMethod;
}


void Renderer::addProgram(Program *_program) {
    program = _program;
}

int Renderer::numberOfVertecis(){
    return myObject->getNrVert();
}

void Renderer::render() {
    setModelMatrix();
    
    if (!bufferIsSet){
        setVertexBuffer();
    }
    
    bufferIsSet = true;
    
    // bind the program (the shaders)
    glUseProgram(program->getProgram());
    
    // bind the VAO (the triangle)
    glBindVertexArray(vao);
    
    // draw the VAO
    glDrawArrays(drawMethod, 0, numberOfVertecis());
    
    // unbind the VAO
    glBindVertexArray(0);
    
    // unbind the program
    glUseProgram(0);
}

Renderer::Renderer() {
    drawMethod = GL_TRIANGLES;
}


void Renderer::setNormals(vector<glm::vec3> normals) {

    // make and bind the VAO
    
    glBindVertexArray(vao);
    
    // make and bind the VBO
    glGenBuffers(1, &vbo_norm);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_norm);
    
    // Put the three triangle verticies into the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normals.size(), &normals[0], GL_STATIC_DRAW);
    
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(program->attrib(NORM_SHADER_NAME));
    glVertexAttribPointer(program->attrib(NORM_SHADER_NAME), 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    // unbind the VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}


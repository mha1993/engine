//
//  Object.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Object.h"

Object::Object() {
    renderer = new Renderer();
	//test -- remove this line it <-----
}

void Object::addVertices(int numVerts, GLfloat *_vertices) {
    cout << _vertices[2]<<endl;
    renderer->addVertices(numVerts, _vertices);
}

glm::vec3 Object::getVertex(int i) {
    return renderer->getVertex(i);
}

int Object::getNumberOfVertices() {
    return renderer->getNumberOfVertices();
}

void Object::setDrawMethod(GLuint _drawMethod) {
    renderer->Renderer::setDrawMethod(_drawMethod);
}

void Object::addProgram(Program *_program) {
    renderer->addProgram(_program);
}

void Object::render() {
    renderer->Renderer::render();
}

void Object::setCameraMatrix(glm::mat4 matrix) {
    renderer->Renderer::setCameraMatrix(matrix);
}

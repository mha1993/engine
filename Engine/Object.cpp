//
//  Object.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Object.h"

#include "Renderer.h"

Object::Object() {
	physics = new PhysicsObject(1.0);
}


void Object::setRenderer(Renderer* renderer){
    this->renderer = renderer;
}

Renderer* Object::getRenderer(){

    return renderer;
}

void Object::render() {
    renderer->Renderer::render();
}



void Object::setPhysics(PhysicsObject * po){
    
    if (physics){
        delete physics;
    }
    
    physics = po;
}

vector<glm::vec3> Object::getVertecis(){
    return vertices;
}
int Object::getNrVert(){
    return vertices.size();
}

void Object::setNRVertAndVertex(vector<glm::vec3> v){
    
    vertices = v;
}

glm::mat4 Object::getModelMatrix() {
    return physics->getModelMatrix();
}

PhysicsObject* Object::getPhysics() {
    return physics;
}
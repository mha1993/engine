//
//  PhysicsObject.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-07.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PhysicsObject.h"
#include <glm/gtc/matrix_transform.hpp>


glm::vec3 PhysicsObject::getPosition() {
    return position;
}

glm::vec3 PhysicsObject::getVelocity() {
    return velocity;
}

glm::mat4 PhysicsObject::getModelMatrix() {
    return glm::translate(glm::mat4(), position)*scaleMatrix;
}

void PhysicsObject::setPosition(glm::vec3 _p) {
    position = _p;
}

void PhysicsObject::setVelocity(glm::vec3 _v) {
    velocity = _v;
}

void PhysicsObject::offsetPosition(glm::vec3 _p) {
    position = position + _p;
}

void PhysicsObject::offsetVelocity(glm::vec3 _v) {
    velocity = velocity + _v;
}

void PhysicsObject::scale(glm::mat4 s) {
    scaleMatrix *= s;
}


PhysicsObject::PhysicsObject() {
    position = glm::vec3();
    velocity = glm::vec3();
}

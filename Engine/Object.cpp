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
}

void Object::addVertices(vector<glm::vec3> *verts) {
    renderer->addVertices(verts);
}

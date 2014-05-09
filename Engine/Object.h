//
//  Object.h
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Object__
#define __Engine__Object__

#include <iostream>
#include <vector>
#include "glm.hpp"
#include <GL/glew.h>
#include "PhysicsObject.h"

class Renderer;

using namespace std;

class Object {
    PhysicsObject *physics;
    
public:
    PhysicsObject* getPhysics();
    vector<glm::vec3> getVertecis();
    int getNrVert();
    
    Object();
    void setRenderer(Renderer* renderer);
    Renderer * getRenderer();
    void render();
    
    void setNRVertAndVertex(vector<glm::vec3> v);
    
    glm::mat4 getModelMatrix();
    
private:
    vector<glm::vec3> vertices;
    Renderer *renderer;
};


#endif /* defined(__Engine__Object__) */

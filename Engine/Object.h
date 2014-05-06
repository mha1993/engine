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

class Renderer;

using namespace std;

class Object {
public:
    
    GLfloat* getVertecis();
    int getNrVert();
    
    Object();
    void setRenderer(Renderer* renderer);
    Renderer * getRenderer();
    void render();
    
    void setNRVertAndVertex(int numberOfVertices,GLfloat *vertices);
    
private:
    int numberOfVertices;
    GLfloat *vertices;
    Renderer *renderer;
};


#endif /* defined(__Engine__Object__) */

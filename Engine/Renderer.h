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
#include <OpenGL/OpenGL.h>

using namespace std;

class Renderer {
    vector<glm::vec3> *vertices;
    
public:
    void addVertices(vector<glm::vec3> *verts);
};

#endif /* defined(__Engine__Renderer__) */

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

#include "Renderer.h"

using namespace std;

class Object {
    Renderer *renderer;
    
public:
    Object();
    void setRenderer(Renderer* renderer);
    Renderer * getRenderer();
    void render();
};

#endif /* defined(__Engine__Object__) */

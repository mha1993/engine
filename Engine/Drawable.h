//
//  Drawable.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Drawable__
#define __Engine__Drawable__

#include <iostream>
#include <GL/glew.h>
#include "glm.hpp"

#define VERT_SHADER_NAME "vert"
#define NORM_SHADER_NAME "aVertexNormal"

using namespace glm;


class Drawable{

public:
    virtual void setMatrices(const mat4 *uMMatrix,const mat4 *uVPMatrix);
    virtual void draw();
    virtual void drawWireframe(vec3 *color);
};


#endif /* defined(__Engine__Drawable__) */

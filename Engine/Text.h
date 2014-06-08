//
//  Text.h
//  Engine
//
//  Created by Mats Allen on 6/7/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Text__
#define __Engine__Text__

#include <iostream>
#include "Program.h"
#include "Texture.h"

#include "GL/glfw.h"

class Text {
    Program *program;
    tdogl::Texture *texture;
    GLuint vbo;
    GLuint vao;
    
public:
    void draw();
    void init();
};

#endif /* defined(__Engine__Text__) */

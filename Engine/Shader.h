//
//  Shader.h
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Shader__
#define __Engine__Shader__

#include <iostream>
#include <string>
#include <GL/glew.h>

using namespace std;

class Shader {
    GLuint shader;
    GLenum type;
    
public:
    Shader(string filename, GLenum t);
    GLuint getShader();
};

#endif /* defined(__Engine__Shader__) */

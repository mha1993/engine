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

#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_map>
#else
#include <hash_map>
#endif


class Text {
    static Program *program;
    
    static hash_map<string, tdogl::Texture*> *textureMap;
    static GLuint vbo;
    static GLuint vao;
    
public:

    static void init();
    static void draw(string imageFileName, float x, float y, float w, float h);
private:
    
    static tdogl::Texture * getTexture(std::string filename);
    
};

#endif /* defined(__Engine__Text__) */

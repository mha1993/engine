//
//  Program.h
//  Engine
//
//  Created by Mats Allen on 5/1/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Program__
#define __Engine__Program__

#include <iostream>
#include <vector>
#include "Shader.h"

using namespace std;

class Program {
    GLuint program;
    
public:
    
    static Program* TeaProgram();
    
    Program(vector<Shader> _shaders);
    GLuint getProgram();
    
    GLint attrib(const GLchar* attribName) const;
    GLint uniform(const GLchar* uniformName) const;
    
    
private:
    static Program *m_teaInstance;
};

#endif /* defined(__Engine__Program__) */

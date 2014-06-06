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

#include <GL/glew.h>

#include <vector>
#include "glm.hpp"
#include <glm/gtc/type_ptr.hpp>
#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_map>
#else
#include <hash_map>
#endif


using namespace std;

using namespace __gnu_cxx;

class Program {
    GLuint program;
    
public:
    
    static Program* fetchProgram(string vs, string fs);
    
    Program(GLuint vs, GLuint fs);
    GLuint getProgram();
    
    GLint attrib(const GLchar* attribName) const;
    GLint uniform(const GLchar* uniformName) const;
    
    void setMatrixUniform(const GLint uniform, const glm::mat4 & mat);
    
private:
    static GLuint makeShader(string filename, GLenum t);
    static hash_map<string, Program *> *instances;
};

#endif /* defined(__Engine__Program__) */

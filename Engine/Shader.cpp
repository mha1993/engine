//
//  Shader.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Shader.h"
#include "FileReader.h"

Shader::Shader(string filename, GLenum t) {
    //create shader
    type = t;
    shader = glCreateShader(type);
    
    //load source
    FileReader *filereader = new FileReader();
    const char *source = filereader->FileReader::readFile(filename).c_str();
    glShaderSource(shader, 1, (const GLchar**)&source, NULL);
    
    //compile shader
    glCompileShader(shader);
    
    //throw exception if compile error occurred
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        string msg("\nCompile failure in shader:\n" + filename);
        
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        char* strInfoLog = new char[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);
        msg += strInfoLog;
        delete[] strInfoLog;
        
        glDeleteShader(shader);
        shader = 0;
        
        cerr << msg << endl;
        exit(EXIT_FAILURE);
        
    } else {
        cout << "Shader compiled from file " << filename << endl;
    }
}

GLuint Shader::getShader() {
    return shader;
}
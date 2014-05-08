//
//  Program.cpp
//  Engine
//
//  Created by Mats Allen on 5/1/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Program.h"



Program::Program(vector<Shader> _shaders) {
    //create the program object
    program = glCreateProgram();
    if(program == 0)
        throw std::runtime_error("glCreateProgram failed");
    
    //attach all the shaders
    for(unsigned i = 0; i < _shaders.size(); ++i)
        glAttachShader(program, _shaders[i].getShader());
    
    //link the shaders together
    glLinkProgram(program);
    
    //detach all the shaders
    for(unsigned i = 0; i < _shaders.size(); ++i)
        glDetachShader(program, _shaders[i].getShader());
    
    //throw exception if linking failed
    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        std::string msg("Program linking failure: ");
        
        GLint infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
        char* strInfoLog = new char[infoLogLength + 1];
        glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
        msg += strInfoLog;
        delete[] strInfoLog;
        
        glDeleteProgram(program); program = 0;
        throw std::runtime_error(msg);
    } else {
        cout << "Successfully linked progam" << endl;
    }
}

GLuint Program::getProgram() {
    return program;
}

GLint Program::attrib(const GLchar* attribName) const {
    if(!attribName)
        throw std::runtime_error("attribName was NULL");
    
    GLint attrib = glGetAttribLocation(program, attribName);
    if(attrib == -1)
        cerr << "Program attribute not found: " << attribName << endl;
        
    return attrib;
}

GLint Program::uniform(const GLchar* uniformName) const {
    if(!uniformName)
        throw std::runtime_error("uniformName was NULL");
    
    GLint uniform = glGetUniformLocation(program, uniformName);
    if(uniform == -1)
        cerr << "Program uniform not found: " << uniformName << endl;
    
    return uniform;
}


Program* Program::m_teaInstance = NULL;

Program* Program::TeaProgram()
{
    if (!Program::m_teaInstance){   // Only allow one instance of class to be generated.
        
        vector<Shader> shaders;
        Shader *vertShader = new Shader::Shader("shader.vsh", GL_VERTEX_SHADER);
        Shader *fragShader = new Shader::Shader("blue.fsh", GL_FRAGMENT_SHADER);
        
        shaders.push_back(*vertShader);
        shaders.push_back(*fragShader);
        
        Program::m_teaInstance = new Program::Program(shaders);
    }
    return Program::m_teaInstance;
}

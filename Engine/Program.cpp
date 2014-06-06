//
//  Program.cpp
//  Engine
//
//  Created by Mats Allen on 5/1/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Program.h"
#include "FileReader.h"

GLuint Program::makeShader(string filename, GLenum t) {
    //create shader
    
    GLuint shader = glCreateShader(t);
    
    //load source
    FileReader *filereader = new FileReader();
    
    string str = filereader->FileReader::readFile(filename);
    const char *source = str.c_str();
    int s = sizeof(char)*str.length();
    const GLint *size = &s;
    
    glShaderSource(shader, 1, (const GLchar**)&source, size);
    
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
    
    return shader;

}

Program::Program(GLuint vs, GLuint fs) {
    //create the program object
    
    
    program = glCreateProgram();
    if(program == 0)
        throw std::runtime_error("glCreateProgram failed");
    
    glAttachShader(program,vs);
    glAttachShader(program,fs);
    
    //link the shaders together
    glLinkProgram(program);
    
    glDetachShader(program,vs);
    glDetachShader(program,fs);
    
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

void Program::setMatrixUniform(const GLint uniform, const glm::mat4 & mat) {
    glUseProgram(program);
    if(uniform == -1){
        //throw std::runtime_error(std::string("Program uniform not found: ") + "model");
    }
    glUniformMatrix4fv(uniform, 1, GL_FALSE, glm::value_ptr(mat));
    glUseProgram(0);
}

hash_map<string, Program *> *Program::instances;

Program* Program::fetchProgram(string vs,string fs)
{
    if (!Program::instances){   // Only allow one instance of class to be generated.
        Program::instances = new hash_map<string, Program*>;
    }
    string key = vs + fs;
    
    hash_map<string, Program *>::iterator i = Program::instances->find(key);
    
    if (i == Program::instances->end()) {
        /* Not found */
        
        GLuint fsp = Program::makeShader(fs, GL_FRAGMENT_SHADER);
        GLuint vsp = Program::makeShader(vs, GL_VERTEX_SHADER);
        
        Program *p = new Program(vsp,fsp);
        
        (*Program::instances)[key] = p;
        return p;
    }
    else {
        /* i->first will contain "apple", i->second will contain 5 */
        return i->second;
    }
}

//
//  Mesh.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-23.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Mesh.h"


Mesh::Mesh(string vs, string fs, vector<vec3> *vp, vector<vec3> *normals,GLuint drawingMethode) : Drawable(){
    
    if (normals != nullptr && vp->size() != normals->size()){
        throw std::runtime_error(std::string("Size on verts and normals differ") + "mesh");
    }
    vert_num = (GLuint) vp->size();
    vbo_norm = -1;
    
    drawMethod = drawingMethode;
    
    program = Program::fetchProgram(vs, fs);
    
    uMMatrixId = program->uniform("uMMatrix");
    uVPMatrixId = program->uniform("uVPMatrix");
    
    // make and bind the VAO
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    // make and bind the VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(program->attrib(VERT_SHADER_NAME));
    glVertexAttribPointer(program->attrib(VERT_SHADER_NAME), 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    
    // Put the verticies into the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vp->size(), &vp->front(), GL_STATIC_DRAW);
    
    if (normals != nullptr){
        
        // make and bind the VBO
        glGenBuffers(1, &vbo_norm);
        glBindBuffer(GL_ARRAY_BUFFER, vbo_norm);
        
        // connect the xyz to the "vert" attribute of the vertex shader
        glEnableVertexAttribArray(program->attrib(NORM_SHADER_NAME));
        glVertexAttribPointer(program->attrib(NORM_SHADER_NAME), 3, GL_FLOAT, GL_FALSE, 0, NULL);
        
        // Put the three triangle verticies into the VBO
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normals->size(), &normals->front(), GL_STATIC_DRAW);
    }
    
    // unbind the VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    
}


void Mesh::setMatrices(const mat4 *uMMatrix,const mat4 *uVPMatrix){
    
    
    program->setMatrixUniform(uMMatrixId,*uMMatrix);
    program->setMatrixUniform(uVPMatrixId,*uVPMatrix);

}
void Mesh::draw(){
    
    // bind the program (the shaders)
    glUseProgram(program->getProgram());
    
    // bind the VAO (the triangle)
    glBindVertexArray(vao);
    
    // draw the VAO
    glDrawArrays(drawMethod, 0, vert_num);
    
    // unbind the VAO
    glBindVertexArray(0);
    
    // unbind the program
    glUseProgram(0);
    
    
}
void Mesh::drawWireframe(vec3 *color){}

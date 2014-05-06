//
//  TileRenderer.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "TileRenderer.h"

#include "Program.h"


void TileRenderer::setVertexBuffer() {
    

    Renderer::setVertexBuffer();
    
    GLfloat *v = myObject->getVertecis();
    
    int nrv = myObject->getNrVert();
    
    glm::vec3 a;
    glm::vec3 b;
    glm::vec3 c;
    
    a.x = v[0];
    a.y = v[1];
    a.z = v[2];
    
    b.x = v[3];
    b.y = v[4];
    b.z = v[5];
    
    c.x = v[6];
    c.y = v[7];
    c.z = v[8];
    
    b = b - a;
    c = c - a;
    
    glm::vec3 norm = glm::cross(b, c);
    
    norm = glm::normalize(norm);
    
    GLfloat normals[nrv * 3];
    for (int i = 0; i< nrv * 3; i+=3){
        normals[i+0] = norm.x;
        normals[i+1] = norm.y;
        normals[i+2] = norm.z;
    }
    
    // make and bind the VAO
    
    glBindVertexArray(vao);
    
    // make and bind the VBO
    glGenBuffers(1, &vbo_norm);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_norm);
    
    // Put the three triangle verticies into the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * nrv * 3, normals, GL_STATIC_DRAW);
    
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(program->attrib(NORM_SHADER_NAME));
    glVertexAttribPointer(program->attrib(NORM_SHADER_NAME), 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    // unbind the VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
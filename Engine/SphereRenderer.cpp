//
//  SphereRenderer.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-07.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "SphereRenderer.h"

#include <vector>
#include "glm.hpp"
#include <glm/gtc/matrix_transform.hpp>


SphereRenderer::SphereRenderer(float r)
{
    int lats = 5;
    int longs = 10;
    
    vector<glm::vec3> vertices;
    vector<glm::vec3> normals;
    
    int i, j;
    for(i = 0; i <= lats; i++) {
        double lat0 = M_PI * (-0.5 + (double) (i - 1) / lats);
        double z0  = sin(lat0);
        double zr0 =  cos(lat0);
        
        double lat1 = M_PI * (-0.5 + (double) i / lats);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);
        
        for(j = 0; j <= longs; j++) {
            double lng = 2 * M_PI * (double) (j - 1) / longs;
            double x = cos(lng);
            double y = sin(lng);
            
            glm::vec3 v = glm::vec3(x * zr0, y * zr0, z0);
            vertices.push_back(v);
            v = glm::vec3(x * zr1, y * zr1, z1);
            vertices.push_back(v);
            
            
        }
    }
    
    numberOfV = vertices.size();
    
    program = Program::fetchProgram("shader.vsh", "blue.fsh");
    
    setDrawMethod(GL_TRIANGLE_STRIP);
    
    // make and bind the VAO
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    // make and bind the VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    // Put the three triangle verticies into the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(program->attrib(VERT_SHADER_NAME));
    glVertexAttribPointer(program->attrib(VERT_SHADER_NAME), 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    
    glGenBuffers(1, &vbo_norm);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_norm);
    
    // Put the three triangle verticies into the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(program->attrib(NORM_SHADER_NAME));
    glVertexAttribPointer(program->attrib(NORM_SHADER_NAME), 3, GL_FLOAT, GL_FALSE, 0, NULL);

    
    // unbind the VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    bufferIsSet = true;
    
}



int SphereRenderer::numberOfVertecis(){

    return numberOfV;
    
}
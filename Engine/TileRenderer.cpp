//
//  TileRenderer.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "TileRenderer.h"

#include "Program.h"


TileRenderer::TileRenderer(){
    
    drawMethod = GL_TRIANGLE_FAN;
    
    program = Program::fetchProgram("shader.vsh", "green.fsh");
    
}

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
    
    setNormals(normals,nrv);
}




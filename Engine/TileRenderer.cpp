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
    
    vector<glm::vec3> v = myObject->getVertecis();
    
    glm::vec3 a = v[0];
    glm::vec3 b = v[1];
    glm::vec3 c = v[2];

    b = b - a;
    c = c - a;
    
    glm::vec3 norm = glm::cross(b, c);
    
    norm = glm::normalize(norm);
    
    vector<glm::vec3> normals;
    for (int i = 0; i<v.size(); i++){
        normals.push_back(norm);
    }
    
    setNormals(normals);
}




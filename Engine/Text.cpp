//
//  Text.cpp
//  Engine
//
//  Created by Mats Allen on 6/7/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Text.h"


void Text::init() {
    
    tdogl::Bitmap bmp = tdogl::Bitmap::bitmapFromFile("/Users/matsallen/Desktop/NOBEL.png");
    bmp.flipVertically();
    texture = new tdogl::Texture(bmp);
    
    program = Program::fetchProgram("textured.vsh", "text.fsh");
    
    // make and bind the VAO
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    // make and bind the VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    // Put the three triangle vertices (XYZ) and texture coordinates (UV) into the VBO
    GLfloat vertexData[] = {
        //  X     Y     Z       U     V
        -1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
        -1.0f,-1.0f, 0.0f,   0.0f, 0.0f,
        1.0f, 1.0f, 0.0f,   1.0f, 1.0f,
        1.0f,-1.0f, 0.0f,   1.0f, 0.0f,
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    
    // connect the xyz to the "vert" attribute of the vertex shader
    glEnableVertexAttribArray(program->attrib("vert"));
    glVertexAttribPointer(program->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), NULL);
    
    // connect the uv coords to the "vertTexCoord" attribute of the vertex shader
    glEnableVertexAttribArray(program->attrib("vertTexCoord"));
    glVertexAttribPointer(program->attrib("vertTexCoord"), 2, GL_FLOAT, GL_TRUE,  5*sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));
    
    // unbind the VAO
    glBindVertexArray(0);
    
}

void Text::draw() {
    cout << "TEXT" << endl;
    glUseProgram(program->getProgram());
    
    // bind the texture and set the "tex" uniform in the fragment shader
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture->object());
    GLuint loc = program->uniform("tex");
    glUniform1i(loc, 0);
    
    // bind the VAO (the triangle)
    glBindVertexArray(vao);
    
    // draw the VAO
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
    
    // unbind the VAO, the program and the texture
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glUseProgram(0);
}

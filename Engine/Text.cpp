//
//  Text.cpp
//  Engine
//
//  Created by Mats Allen on 6/7/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Text.h"
#include "FileReader.h"


Program *Text::program;
hash_map<string, tdogl::Texture*> *Text::textureMap;

GLuint Text::vbo;
GLuint Text::vao;

tdogl::Texture* Text::getTexture(string filename){
    
    if (!Text::textureMap){   // Only allow one instance of class to be generated.
        Text::textureMap = new hash_map<string, tdogl::Texture*>;
    }
    
    hash_map<string, tdogl::Texture*>::iterator i = Text::textureMap->find(filename);
    
    if (i == Text::textureMap->end()) {
        /* Not found */
        
        string fullPath = FileReader::makePath(filename);
        
        tdogl::Bitmap bmp = tdogl::Bitmap::bitmapFromFile(fullPath);
        bmp.flipVertically();
        tdogl::Texture* texture = new tdogl::Texture(bmp);
        
        (*Text::textureMap)[filename] = texture;
        
        return texture;
        
    }
    else {
        /* i->first will contain "apple", i->second will contain 5 */
        return i->second;
    }
    
    
}


void Text::init() {
    

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


void Text::draw(string imageFileName, float x, float y, float w, float h){

    
    glUseProgram(program->getProgram());
    
    // bind the texture and set the "tex" uniform in the fragment shader
    glActiveTexture(GL_TEXTURE0);
    
    tdogl::Texture *t = getTexture(imageFileName);
    
    glBindTexture(GL_TEXTURE_2D, t->object());
    GLuint loc = program->uniform("tex");
    glUniform1i(loc, 0);
    
    loc = program->uniform("coord");
    glUniform2f(loc,x,y);
    
    loc = program->uniform("size");
    glUniform2f(loc,w,h);
    
    // bind the VAO (the triangle)
    glBindVertexArray(vao);
    
    // draw the VAO
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    
    // unbind the VAO, the program and the texture
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glUseProgram(0);

}

//
//  Mesh.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-23.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Mesh__
#define __Engine__Mesh__

#include <iostream>
#include <string>
#include <vector>

#include "Program.h"
#include "Drawable.h"
/**
 
 
 {
 "materials" : [ {"vertexshader" : "shaders/01.vs", "fragmentshader" : "shaders/yellow_norm.fs", "numindices" : 6}],
 "indices" : [0,1,2, 2,3,0],
 "vertexPositions" : [-1.0,-1.0,0.0, -1.0,1.0,0.0, 1.0,1.0,0.0, 1.0,-1.0,0.0],
 "vertexNormals" : [0,0,1, 0,0,1, 0,0,1, 0,0,1]
 }
 
 
 */

using namespace glm;
using namespace std;

class Mesh : public Drawable{
    
    GLuint uMMatrixId;
    GLuint uVPMatrixId;
    GLuint rotMatId;
    
    GLuint vao;
    GLuint vbo;
    GLuint vbo_norm;
    
    GLuint drawMethod;
    GLuint vert_num;
    
    Program *program;
    
public:
    Mesh(string vs, string fs, vector<vec3> *vp, vector<vec3> *normals,GLuint drawingMethode);
    void setMatrices(const mat4 *uMMatrix,const mat4 *uVPMatrix, const mat4 rot = mat4());
    void draw();
    void drawWireframe(vec3 *color);
    Program* getProgram();
};





#endif /* defined(__Engine__Mesh__) */

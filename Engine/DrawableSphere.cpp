//
//  DrawableSphere.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "DrawableSphere.h"
#include "Program.h"
#include <vector>


DrawableSphere::DrawableSphere(float radius, unsigned int rings, unsigned int sectors,string vs, string fs){
    
    vector<vec3> *normals       = new vector<vec3>;
    vector<vec3> *verts         = new vector<vec3>;
    
    int lats = 15;
    int longs = 30;
    
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
            verts->push_back(v * radius);
            normals->push_back(v);
            v = glm::vec3(x * zr1, y * zr1, z1);
            verts->push_back(v * radius);
            normals->push_back(v);
            
        }
    }
    
    mesh = new Mesh(vs,fs,verts,normals,GL_TRIANGLE_STRIP);
    
}


void DrawableSphere::setMatrices(const mat4 *uMMatrix,const mat4 *uVPMatrix){

    mesh->setMatrices(uMMatrix, uVPMatrix);
    
}
void DrawableSphere::draw(){

    mesh->draw();
    
}
void DrawableSphere::drawWireframe(vec3 *color){}
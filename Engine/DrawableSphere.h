//
//  DrawableSphere.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__DrawableSphere__
#define __Engine__DrawableSphere__

#include <iostream>
#include "Drawable.h"
#include "Program.h"


#include "Mesh.h"


#define BUFFER_OFFSET(i) ((char *)NULL + (i))

using namespace glm;
using namespace std;

class DrawableSphere : public Drawable{

    
    
public:
    
    DrawableSphere(float rad, unsigned int rings, unsigned int sectors, string vs, string fs);
    
    void setMatrices(const mat4 *uMMatrix,const mat4 *uVPMatrix, const mat4 rot);
    void draw();
    void drawWireframe(vec3 *color);
    
    Mesh * mesh;
    
};



#endif /* defined(__Engine__DrawableSphere__) */

//
//  SphereRenderer.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-07.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__SphereRenderer__
#define __Engine__SphereRenderer__

#include <iostream>
#include "Renderer.h"


#endif /* defined(__Engine__SphereRenderer__) */


class SphereRenderer : public Renderer {

    int numberOfV;
    
public:
    SphereRenderer();
    
protected:
    int numberOfVertecis();
}; 
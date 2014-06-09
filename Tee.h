//
//  Tee.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Tee__
#define __Engine__Tee__

#include <iostream>

#include "GameObject.h"

class Tee : public GameObject{
    
public:
    
    Tee(vec3 pos, float size, int idd);
    std::string name();
    
};

#endif /* defined(__Engine__Tee__) */

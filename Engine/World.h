//
//  World.h
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__World__
#define __Engine__World__

#include <iostream>
#include <vector>

#include "Object.h"

class World {
    vector<Object*> objects;
    
public:
    void init();
};

#endif /* defined(__Engine__World__) */

//
//  BaseLevel.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-24.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__BaseLevel__
#define __Engine__BaseLevel__

#include <iostream>
#include <vector>
#include "GameObject.h"

using namespace std;

class BaseLevel{
    
    vector<GameObject *> gameObjects;
    int addObject();
    
public:
    
    void stop();
    virtual void setup();
    virtual void start();
    virtual void teardown();
    virtual void tick(float deltaTime);
    virtual void render();
    
};




#endif /* defined(__Engine__BaseLevel__) */

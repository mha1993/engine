//
//  Level.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Level__
#define __Engine__Level__

#include <iostream>
#include <vector>
#include "WindowManager.h"

using namespace std;

class Level{
    
protected:
    WindowManager *windowManager;
    bool shouldBeRunning;
public:
    
    Level(WindowManager *wm);
    virtual void run();
    virtual void setup();
    virtual void teardown();
    virtual void tick(float deltaTime);
    virtual void render();
    
    
    void sleep(long millis);
};

#endif /* defined(__Engine__Level__) */

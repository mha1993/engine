//
//  HudRenderer.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__HudRenderer__
#define __Engine__HudRenderer__

#include <iostream>
#include <vector>
#include "HudElement.h"
#include "WindowManager.h"

using namespace std;

class HudRenderer{

    WindowManager *windowManager;
    vector<HudElement *> elements;
    
public:
    HudRenderer(WindowManager *wm);
    void addElement(HudElement * element);
    void removeElement(HudElement * element);
    void removeAllElements();
    void render();
    void tick(float deltaT);
};


#endif /* defined(__Engine__HudRenderer__) */

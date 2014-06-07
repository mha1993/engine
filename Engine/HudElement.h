//
//  HudElement.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__HudElement__
#define __Engine__HudElement__

#include <iostream>

using namespace std;

class HudElement{
    
public:
    HudElement();
    virtual void render();
    virtual void tick(float deltaT);
    
protected:
    void drawText(string s, float x, float y);
    void drawImage(string imageName, float x, float y, float width, float height);
};

#endif /* defined(__Engine__HudElement__) */

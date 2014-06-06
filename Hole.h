//
//  Hole.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Hole__
#define __Engine__Hole__

#include <iostream>

#include "BaseLevel.h"

#include <string>

#include "glm.hpp"

using namespace glm;
using namespace std;

class Hole : public BaseLevel{
    
    string name;

public:
    Hole(WindowManager *wm);
    void setName(string name);
    void addTile(vector<string> thing, int lineid);
    void addCup(vector<string> thing, int lineid);
    void addTee(vector<string> thing, int lineid);
    
private:
    void addWall(vec3 a, vec3 b);
    
};


#endif /* defined(__Engine__Hole__) */

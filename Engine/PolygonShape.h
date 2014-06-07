//
//  PolygonShape.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-24.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__PolygonShape__
#define __Engine__PolygonShape__

#include <iostream>

#include <vector>
#include "PhysicShape.h"

#include "glm.hpp"

using namespace glm;
using namespace std;

class PolygonShape : public PhysicShape{
    
    
    vector<vec3> edges;
    
public:
    PolygonShape(vector<vec3> v);
    vector<vec3> getVerts();
    vec3 mSupport(vec3 dir);
    std::string getName();
};

#endif /* defined(__Engine__PolygonShape__) */

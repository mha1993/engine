//
//  Physics2.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-24.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Physics2__
#define __Engine__Physics2__

#include <iostream>


#include "PObject.h"

#include <vector>

#include "glm.hpp"

#include "PolygonShape.h"

#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_map>
#else
#include <hash_map>
#endif

using namespace __gnu_cxx;


using namespace glm;
using namespace std;

class Physics2{

    static int idCounter;
    
    vector<PObject *> im;
    vector<PObject *> mv;
    hash_map<int, PObject *> all;

public:
    
    Physics2();
    static const int SHAPE_SPHERE = 1;
    static const int SHAPE_CONVEX_POLY = 2;
    
    int addObject(int physicsShape, float size, vector<vec3> vert, vec3 pos, vec3 vel, bool movable, bool colidable);
    
    vec3 getVel(int id);
    vec3 getPos(int id);
    float getSize(int id);
    
    void setVel(int id, vec3 vel);
    void setPos(int id, vec3 pos);
    void setSize(int id, float size);
    
    void tick(float tickTime);
    
private:
    
    PObject * getObject(int id);

};



#endif /* defined(__Engine__Physics2__) */

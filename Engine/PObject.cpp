//
//  PObject2.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-24.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PObject.h"




PObject::PObject(int idd, PhysicShape *pss, vec3 poss, bool collidablee){
    
        id = idd;
        ps = pss;
        size = 1.0f;
        pos = poss;
        vel = vec3(0.0,0.0,0.0);
        collidable = collidablee;
    
}

PObject::PObject(int idd, PhysicShape *pss, vec3 poss, vec3 vell, bool collidablee, float sizee){
    id =idd;
    ps = pss;
    size = sizee;
    pos = poss;
    vel = vell;
    collidable = collidablee;
}
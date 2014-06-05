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
    pos = poss;
    collidable = collidablee;
    
    size = 1.0f;
    vel = vec3(0.0,0.0,0.0);
    isStatic = true;
}

PObject::PObject(int idd, PhysicShape *pss, vec3 poss, vec3 vell, bool collidablee, float sizee,bool stat){
    
    id =idd;
    ps = pss;
    size = sizee;
    pos = poss;
    vel = vell;
    collidable = collidablee;
    isStatic = stat;
}
//
//  TestLevel.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "TestLevel.h"

#include "Tile.h"

void TestLevel::setup(){
    
    
    vector<vec3> v;
    
    v.push_back(vec3(0.0,0.0,0.0));
    v.push_back(vec3(0.0,1.0,0.0));
    v.push_back(vec3(1.0,0.0,0.0));
    
    GameObject *tile = new Tile(v,0);
    
    this->addObject(tile);
    
}
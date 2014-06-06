//
//  TestLevel.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "TestLevel.h"
#include "Tile.h"
#include "Tee.h"
#include "Cup.h"

void TestLevel::setup(){
    
    vector<vec3> v;
    
    v.push_back(vec3(0.0,0.0,0.0));
    v.push_back(vec3(0.0,1.0,0.0));
    v.push_back(vec3(1.0,0.0,0.0));
    
    GameObject *tile = new Tile(v,0);
    this->addObject(tile);
    
    GameObject *tee = new Tee(vec3(-1.0,0.0,0.0),1.0,1);
    
    this->addObject(tee);
    
    GameObject *cup = new Cup(vec3(-1.0,-1.0,0.0), vec3(1.0,1.0,1.0),  1.0, 2);
    
    this->addObject(cup);
    
    GameObject *ball = new Ball
    
}
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
#include "Wall.h"
#include "Ball.h"

void TestLevel::setup(){
    
    vector<vec3> v;
    
    v.push_back(vec3(3.0,0.0,-10.0));
    v.push_back(vec3(3.0,20.0,-10.0));
    v.push_back(vec3(2.7,0.0,10.0));
    
    
    GameObject *tile = new Tile(v,0);
    this->addObject(tile);
    
    
    v.clear();
    
    v.push_back(vec3(-10.0,0.0,-10.0));
    v.push_back(vec3(-10.0,20.0,-10.0));
    v.push_back(vec3(-10.7,0.0,10.0));
    
    
    GameObject *tile2 = new Tile(v,1);
    this->addObject(tile2);
    
    /*
    
    GameObject *tee = new Tee(vec3(-1.0,0.0,0.0),1.0,1);
    
    this->addObject(tee);
    
    GameObject *cup = new Cup(vec3(-1.0,-1.0,0.0), vec3(1.0,1.0,1.0),  1.0, 2);
    
    this->addObject(cup);

    GameObject *wall = new Wall(v[0], v[2], .2f , 3);
    
    this->addObject(wall);
     
     */
    
    GameObject *ball = new Ball(vec3(1.0, 1.0, 1.0), vec3(0,0,0), 1.0f, 2);
    ball->getPhysicsObject()->isStatic = false;
    ball->getPhysicsObject()->vel = glm::vec3(5,0,0);
    
    this->addObject(ball);
    
    currentCamera->setPosition(vec3(0,0,10));
    
}


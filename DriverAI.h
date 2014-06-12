//
//  DriverAI.h
//  Engine
//
//  Created by Mats Allen on 6/9/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__DriverAI__
#define __Engine__DriverAI__

#include <iostream>
#include "Ball.h"
#include <glm.hpp>
#include <vector>
#include "GameObject.h"
#include "SceneManager.h"

using namespace std;

class DriverAI {
    Ball *ball;
    vector<vec3> waypoints;
    int curWaypoint;
    SceneManager *sm;
    
public:
    DriverAI(Ball *_ball, SceneManager *sm, int idStart, int idEnd, int idHole);
    void addWaypoint(vec3 wp);
    void calcWaypoints(SceneManager *sm, int idStart, int idEnd);
    void tick(float dt);
    
    void showWaypoints(SceneManager *sm);
};

#endif /* defined(__Engine__DriverAI__) */

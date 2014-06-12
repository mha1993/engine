//
//  DriverAI.h
//  Engine
//
//  AI controller used to drive ball to hole
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

//
//  CourseHole.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "CourseHole.h"


CourseHole::CourseHole(WindowManager *wm) : Hole(wm){}

void CourseHole::tick(float deltaTime){

    if (windowManager->quitRequest()){
        shouldBeRunning = false;
    }

    Hole::tick(deltaTime);
}

void CourseHole::setup(){

    Hole::setup();
    
    float ballRadius = 0.05;
    
    vec3 teeLoc = tee->getPhysicsObject()->pos;

    float h = 0.2;
    
    vec3 ballLoc = teeLoc + vec3(0,ballRadius,0);
    
    printf("setup:objectID %d\n",cup->objectId);
    
    ball = new GameBall(ballLoc,ballRadius,1000001,cup->objectId);
    
    this->addObject(ball);
    
    
    currentCamera->setPosition(teeLoc + vec3(1,1,1));
    currentCamera->lookAt(teeLoc);
    
}
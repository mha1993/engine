//
//  CourseHole.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "CourseHole.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Bitmap.h"
#include "Texture.h"
#include "Text.h"
#include "Gravity.h"


CourseHole::CourseHole(WindowManager *wm) : Hole(wm){
    windowManager = wm;
}

void CourseHole::shoot_setup(float dt) {
    if(windowManager->getKey('T')) {
        arrow->getPhysicsObject()->rot = rotate(arrow->getPhysicsObject()->rot, dt*90.0f, vec3(0,1,0));
    }
    if(windowManager->getKey('Y')) {
        arrow->getPhysicsObject()->rot = rotate(arrow->getPhysicsObject()->rot, -dt*90.0f, vec3(0,1,0));
    }
    arrow->getPhysicsObject()->pos = ball->getPhysicsObject()->pos + vec3(0,0.05,0);
}

void CourseHole::shoot() {
    float speed = 0.2;
    vec4 dir = vec4(0,0,-1,0) * arrow->getPhysicsObject()->rot;
    ball->getPhysicsObject()->vel += speed*vec3(dir);
    //shoot_mode = false;
}

void CourseHole::tick(float deltaTime){

    if (windowManager->quitRequest()){
        shouldBeRunning = false;
    }
    
    if (shoot_mode) shoot_setup(deltaTime);
    if (windowManager->getKey(' ') && shoot_mode) {
        shoot();
    }

    Hole::tick(deltaTime);
    
}

void CourseHole::setup(){
    
    shoot_mode = true;
    
    Hole::setup();
    
    float ballRadius = 0.05;
    
    vec3 teeLoc = cup->getPhysicsObject()->pos;

    float h = 0.2;
    
    vec3 ballLoc = teeLoc + vec3(0.1,ballRadius + h,0);
    
    printf("setup:objectID %d\n",cup->objectId);
    
    ball = new GameBall(ballLoc,ballRadius,1000001,cup->objectId);
    ball->getPhysicsObject()->vel = vec3(0,0,0);
    
    this->addObject(ball);
    
    addArrow(1000002);
    
    currentCamera->setPosition(teeLoc + vec3(1,1,1));
    currentCamera->lookAt(teeLoc);
    
    Gravity *g = new Gravity();
    physicsEngine->addForce((Force*)g);
    
}


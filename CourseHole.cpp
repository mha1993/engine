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

void CourseHole::shoot_setup() {
    arrow->getPhysicsObject()->rot = rotate(mat4(), 90.0f, vec3(0,1,0));
    arrow->getPhysicsObject()->pos = ball->getPhysicsObject()->pos + vec3(0,0.05,0);
}

void CourseHole::shoot() {
    ball->getPhysicsObject()->vel += vec3(0.03,0.03,0.03);
    //shoot_mode = false;
}

void CourseHole::tick(float deltaTime){

    if (windowManager->quitRequest()){
        shouldBeRunning = false;
    }
    
    if (shoot_mode) shoot_setup();
    if (windowManager->getKey(' ') && shoot_mode) {
        shoot();
    }

    Hole::tick(deltaTime);
    
}

void CourseHole::setup(){
    shoot_mode = true;
    
    Hole::setup();
    
    float ballRadius = 0.05;
    
    vec3 teeLoc = tee->getPhysicsObject()->pos;

    float h = 0.04;
    
    vec3 ballLoc = teeLoc + vec3(0,ballRadius + h,0);
    
    vec3 cuploc = cup->getPhysicsObject()->pos;
    
    printf("setup:%s cupid %d (%f %f %f)\nball (%f %f %f)\n",name.c_str(),cup->objectId,cuploc.x,cuploc.y,cuploc.z,ballLoc.x,ballLoc.y,ballLoc.z);
    
    ball = new GameBall(ballLoc,ballRadius,1000001,cup->objectId);
    ball->getPhysicsObject()->vel = - vec3(0,0.1,0);
    
    this->addObject(ball);
    
    addArrow(1000002);
    
    currentCamera->setPosition(teeLoc + vec3(1,1,1));
    currentCamera->lookAt(teeLoc);
    
    Gravity *g = new Gravity();
    physicsEngine->addForce((Force*)g);
    
}


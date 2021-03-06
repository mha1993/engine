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
#include "FollowCamera.h"

#define TURN_SPEED 360.0f


CourseHole::CourseHole(WindowManager *wm, HudRenderer * hd, ScoreKeeper *sk) : Hole(wm,hd){
    windowManager = wm;
    scoreKeeper = sk;
    cameracounter = 0;
}

void CourseHole::shoot_setup(float dt) {
    if(windowManager->getKey('T')) {
        arrow->getPhysicsObject()->rot = rotate(arrow->getPhysicsObject()->rot, dt*TURN_SPEED, vec3(0,1,0));
    }
    if(windowManager->getKey('Y')) {
        arrow->getPhysicsObject()->rot = rotate(arrow->getPhysicsObject()->rot, -dt*TURN_SPEED, vec3(0,1,0));
    }
    arrow->getPhysicsObject()->pos = balls[0]->getPhysicsObject()->pos + vec3(0,0.05,0);
}

void CourseHole::shoot() {
    float speed = 0.2;
    vec4 dir = vec4(0,0,1,0) * arrow->getPhysicsObject()->rot;
    dir.x *= -1;
    
    balls[0]->getPhysicsObject()->vel += speed*vec3(dir);
    //shoot_mode = false;
}

void CourseHole::tick(float deltaTime){

    if (windowManager->quitRequest()){
        stop();
        
    }
    
    if (balls[0]->getPhysicsObject()->pos.y < -10) {
        stop();
    }
    
    if (shoot_mode) shoot_setup(deltaTime);
    if (windowManager->getKey(' ') && shoot_mode) {
        shoot();
    }
    
    if (windowManager->getKey('P')) {
        currentCamera = cameras[++cameracounter % cameras.size()];
    }
    
    for (int i=0; i<ais.size(); i++) {
        ais[i]->tick(deltaTime);
    }

    Hole::tick(deltaTime);
    
}

void CourseHole::setup(){
    
    shoot_mode = true;
    
    Hole::setup();
    
    float ballRadius = 0.05;
    
    vec3 teeLoc = tee->getPhysicsObject()->pos;

    float h = 0.04;
    
    vec3 ballLoc = teeLoc + vec3(0.1,ballRadius + h,0);
    
    vec3 cuploc = cup->getPhysicsObject()->pos;
    
    printf("setup:%s cupid %d (%f %f %f)\nball (%f %f %f)\n",name.c_str(),cup->objectId,cuploc.x,cuploc.y,cuploc.z,ballLoc.x,ballLoc.y,ballLoc.z);
    
    Ball *ball = new GameBall(ballLoc,ballRadius,1000001,cup->objectId);
    ball->getPhysicsObject()->vel = vec3(0,0,0);
    
    this->addObject(ball);
    balls.push_back(ball);
    
    Ball *ball2 = new GameBall(ballLoc+vec3(-0.1,0.3,0),ballRadius,1000002,cup->objectId);
    ball2->getPhysicsObject()->vel = vec3(0,0,0);
    
    DriverAI *ai = new DriverAI::DriverAI(ball2, sceneManager, tee->tileId, cup->tileId, cup->objectId);
    ai->showWaypoints(sceneManager);
    
    this->addObject(ball2);
    balls.push_back(ball2);
    ais.push_back(ai);
    
    
    
    addArrow(1000002);
    
    currentCamera->setPosition(teeLoc + vec3(1,1,1));
    currentCamera->lookAt(teeLoc);
    
    cameras.push_back(currentCamera);
    cameras.push_back(new FollowCamera(ball->getPhysicsObject()));
    
    Gravity *g = new Gravity();
    physicsEngine->addForce((Force*)g);
    
}


void CourseHole::stop(){
    
    scoreKeeper->miss();
    
    Hole::stop();
    
}

void CourseHole::goal(){
    scoreKeeper->hit();
    Hole::stop();
}



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


CourseHole::CourseHole(WindowManager *wm) : Hole(wm){}

void CourseHole::shoot() {
    arrow->getPhysicsObject()->rot = rotate(mat4(), 90.0f, vec3(0,1,0));
    arrow->getPhysicsObject()->pos = ball->getPhysicsObject()->pos + vec3(0,0.05,0);
}

void CourseHole::tick(float deltaTime){

    if (windowManager->quitRequest()){
        shouldBeRunning = false;
    }
    
    if (shoot_mode) shoot();

    Hole::tick(deltaTime);
    //text->Text::draw();
    
}

void CourseHole::setup(){
    shoot_mode = true;
    
    Hole::setup();
    
    float ballRadius = 0.05;
    
    vec3 teeLoc = cup->getPhysicsObject()->pos;

    float h = 0.2;
    
    vec3 ballLoc = teeLoc + vec3(0,ballRadius + h,0);
    
    printf("setup:objectID %d\n",cup->objectId);
    
    ball = new GameBall(ballLoc,ballRadius,1000001,cup->objectId);
    
    this->addObject(ball);
    
    addArrow(1000002);
    
    currentCamera->setPosition(teeLoc + vec3(1,1,1));
    currentCamera->lookAt(teeLoc);
    
//    text = new Text();
//    text->init();
    
    
}


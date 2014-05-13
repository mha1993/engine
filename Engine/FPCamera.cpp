//
//  FPCamera.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-13.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "FPCamera.h"

#include <GL/glfw.h>





void FPCamera::update(float secondsElapsed){
    
    //move position of camera based on WASD keys, and XZ keys for up and down
    const float moveSpeed = 8.0; //units per second
    if(glfwGetKey('S')){
        offsetPosition(secondsElapsed * moveSpeed * -forward());
    } else if(glfwGetKey('W')){
        offsetPosition(secondsElapsed * moveSpeed * forward());
    }
    if(glfwGetKey('A')){
        offsetPosition(secondsElapsed * moveSpeed * -right());
    } else if(glfwGetKey('D')){
        offsetPosition(secondsElapsed * moveSpeed * right());
    }
    if(glfwGetKey('Z')){
        offsetPosition(secondsElapsed * moveSpeed * -glm::vec3(0,1,0));
    } else if(glfwGetKey('X')){
        offsetPosition(secondsElapsed * moveSpeed * glm::vec3(0,1,0));
    }
    
    float angleSpeed = 8.0f;
    
    if (glfwGetKey('I')){
        offsetOrientation(secondsElapsed * moveSpeed * angleSpeed, 0);
    }else if (glfwGetKey('K')){
        offsetOrientation( - secondsElapsed * moveSpeed * angleSpeed, 0);
    }
    if (glfwGetKey('L')){
        offsetOrientation(0, secondsElapsed * moveSpeed * angleSpeed);
        
    }else if (glfwGetKey('J')){
        offsetOrientation(0, - secondsElapsed * moveSpeed * angleSpeed);
    }
    
}
//
//  GameBall.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "GameBall.h"
#include "BaseLevel.h"
#include <CourseHole.h>

GameBall::GameBall(glm::vec3 pos, float size, int idd, int goalID) : Ball(pos,vec3(0,0,0),size,idd){
    this->goalID = goalID;
}
void GameBall::collidedWith(GameObject *other, vec3 hitNormal, vec3 pos){

    if (other->objectId == goalID){
        
        CourseHole *ch = (CourseHole *) Ball::level;
        ch->goal();
        
    }else{
        Ball::collidedWith(other,hitNormal,pos);
    }
}

std::string GameBall::name(){
    return "GameBall";
}
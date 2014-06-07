//
//  GameBall.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "GameBall.h"
#include "BaseLevel.h"

GameBall::GameBall(glm::vec3 pos, float size, int idd, int goalID) : Ball(pos,vec3(0,-.07,0),size,idd){
    this->goalID = goalID;
}
void GameBall::collidedWith(GameObject *other, vec3 hitNormal, vec3 pos){
    
    printf("col: %d, %d\ngoal%d\n",this->objectId,other->objectId,goalID);
    
    if (other->objectId == goalID){
        Ball::level->stop();
    }else{
        
        Ball::collidedWith(other,hitNormal,pos);
    }
}
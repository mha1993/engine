//
//  GameBall.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__GameBall__
#define __Engine__GameBall__

#include <iostream>


#include "Ball.h"



class GameBall : public Ball{
    
public:
    GameBall(glm::vec3 pos, float size, int idd, int goalID);
    virtual void collidedWith(GameObject *other, vec3 hitNormal, vec3 pos) override;
    
    std::string name();

protected:
    int goalID;
};



#endif /* defined(__Engine__GameBall__) */

//
//  Ball.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Ball__
#define __Engine__Ball__

#include <iostream>

#include "GameObject.h"


class Ball : public GameObject{

public:
    
    Ball(glm::vec3 pos, glm::vec3 vel, float size, int idd);

    virtual void collidedWith(GameObject *other, vec3 hitNormal, vec3 pos);
};



#endif /* defined(__Engine__Ball__) */

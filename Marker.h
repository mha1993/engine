//
//  Marker.h
//  Engine
//
//  Created by Mats Allen on 6/12/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Marker__
#define __Engine__Marker__

#include <iostream>
#include "Ball.h"

class Marker : Ball {
    
public:
    virtual void tick(float dt)override;
    Marker(glm::vec3 pos, glm::vec3 vel, float size, int idd);
};

#endif /* defined(__Engine__Marker__) */

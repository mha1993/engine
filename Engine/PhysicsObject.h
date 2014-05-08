//
//  PhysicsObject.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-07.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__PhysicsObject__
#define __Engine__PhysicsObject__

#include <iostream>


class PhysicsObject{

    /**
        returns the time it takes before objects collide if both remain in current speed
        returns -1 if the objects will not collide within maxtime
     */
    float timeToCollision(PhysicsObject *po, float maxTime);

    
    
};



#endif /* defined(__Engine__PhysicsObject__) */

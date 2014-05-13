//
//  FollowCamera.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-13.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__FollowCamera__
#define __Engine__FollowCamera__

#include <iostream>
#include "Camera.h"
#include "PhysicsObject.h"

#endif /* defined(__Engine__FollowCamera__) */

using namespace tdogl;

class FollowCamera : public Camera{

    PhysicsObject *followObject;
    
    FollowCamera(PhysicsObject *po );
    
};
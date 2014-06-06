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
#include "PObject.h"
#include "ECamera.h"

#endif /* defined(__Engine__FollowCamera__) */


class FollowCamera : public ECamera{

    PObject *followObject;
    glm::vec3 lastPos;
public:
    FollowCamera(PObject *po );
    glm::mat4 matrix();
    void update(float time);
};
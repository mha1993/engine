//
//  ECamera.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-13.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__ECamera__
#define __Engine__ECamera__

#include <iostream>
#include "Camera.h"


class ECamera : public tdogl::Camera{
    
public:
    virtual void update(float time);
    
};


#endif /* defined(__Engine__ECamera__) */
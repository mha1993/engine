//
//  CourseHole.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__CourseHole__
#define __Engine__CourseHole__

#include <iostream>
#include "Hole.h"
#include "Text.h"

#include "GameBall.h"


class CourseHole : public Hole{
    bool shoot_mode;
    Text *text;
    WindowManager *windowManager;

public:
    CourseHole(WindowManager *wm);

protected:
    void tick(float deltaTime);
    void setup();
    void shoot_setup();
    void shoot();
};


#endif /* defined(__Engine__CourseHole__) */

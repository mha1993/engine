//
//  CourseHole.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "CourseHole.h"



CourseHole::CourseHole(WindowManager *wm) : Hole(wm){}





void CourseHole::tick(float deltaTime){

    if (windowManager->quitRequest()){
        shouldBeRunning = false;
    }

    Hole::tick(deltaTime);
    
}
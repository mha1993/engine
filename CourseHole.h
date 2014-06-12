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

#include "GameBall.h"
#include "HudRenderer.h"
#include "ScoreKeeper.h"
#include "DriverAI.h"


class CourseHole : public Hole{
    bool shoot_mode;
    WindowManager *windowManager;
    ScoreKeeper *scoreKeeper;
    
    vector<ECamera *> cameras;
    
    int cameracounter;
    
    vector<DriverAI*> ais;
    
public:
    CourseHole(WindowManager *wm,HudRenderer * hr, ScoreKeeper *sk);

    void stop();
    void goal();
    
protected:
    void tick(float deltaTime);
    void setup();
    void shoot_setup(float dt);
    void shoot();
    
};


#endif /* defined(__Engine__CourseHole__) */

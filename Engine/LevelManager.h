//
//  LevelManager.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__LevelManager__
#define __Engine__LevelManager__

#include <iostream>

#include "Level.h"

class LevelManager : public Level{

protected:
    Level * current;
    vector<Level*> levels;
public:
    void setup();

};

#endif /* defined(__Engine__LevelManager__) */

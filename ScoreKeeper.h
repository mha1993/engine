//
//  ScoreKeeper.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-09.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__ScoreKeeper__
#define __Engine__ScoreKeeper__

#include <iostream>

#include "HudElement.h"

#include <vector>

class ScoreKeeper : public HudElement{

    vector<int> score;
    
public:
    
    ScoreKeeper();
    
    void hit();
    void miss();
    void render();

};

#endif /* defined(__Engine__ScoreKeeper__) */

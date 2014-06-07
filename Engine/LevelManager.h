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


#include "Hole.h"
#include "FileReader.h"
#include "TextUtils.h"

#define COURSE "course"
#define BEGIN_HOLE "begin_hole"
#define END_HOLE "end_hole"

class LevelManager : public Level{

protected:
    string name;
    int current;
    vector<Hole*> levels;
public:
    LevelManager(WindowManager *wm);
    void setup();

    void run();
    
private:
    Hole * last();
 

};

#endif /* defined(__Engine__LevelManager__) */

//
//  World.h
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__World__
#define __Engine__World__

#include <iostream>
#include <vector>

#include "Map.h"
#include "Camera.h"

class World {
    Map *map;
    tdogl::Camera *camera;
    
public:
    void init();

private:
    void loadMap();
    void renderScene();
    void Update(float secondsElapsed);
};

#endif /* defined(__Engine__World__) */

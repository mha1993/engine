//
//  Wall.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Wall__
#define __Engine__Wall__

#include <iostream>

#include "GameObject.h"


class Wall : public GameObject{

public:
    Wall(vec3 a, vec3 b, float height, int idd);

};


#endif /* defined(__Engine__Wall__) */

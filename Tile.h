//
//  Tile.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__Tile__
#define __Engine__Tile__

#include <iostream>


#include "Mesh.h"


#include "GameObject.h"

class Tile : public GameObject{

public:
    Tile(vector<glm::vec3> verts , int idd);
};

#endif /* defined(__Engine__Tile__) */

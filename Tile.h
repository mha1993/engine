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

#include <map>
#include "Mesh.h"


#include "GameObject.h"

class Tile : public GameObject{
    vector<pair<int, int>> neighbors;

public:
    Tile(vector<glm::vec3> verts , int idd);
    std::string name();
    
    void addNeighbor(int idd, int edge);
    vector<pair<int, int>> getNeighbors();
    pair<vec3, vec3> getEdge(int e);
};

#endif /* defined(__Engine__Tile__) */

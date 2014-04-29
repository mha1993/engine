//
//  main.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include <iostream>

#include "World.h"

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Initializing world object\n";
    World *world = new World::World();
    world->init(argc, argv);
    
    return 0;
}


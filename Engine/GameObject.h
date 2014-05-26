//
//  GameObject.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-23.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__GameObject__
#define __Engine__GameObject__

#include <iostream>


class GameObject{
    
    const int objectId;
    int physicsID;

public:
    GameObject(int idd);
    GameObject();
    virtual void tick(float tickTime);
    
private:
    
    bool addPhysics();
    
    
};

#endif /* defined(__Engine__GameObject__) */
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
#include "PObject.h"
#include "Drawable.h"

class GameObject{
    
    const int objectId;
    int physicsID;

protected:
    PObject *physicsObject;
    Drawable* mesh;

public:
    GameObject(int idd);
    PObject* getPhysicsObject();
    Drawable* getMesh();
    
    
    virtual void tick(float tickTime);
    virtual void collidedWith(GameObject *other, vec3 hitNormal, vec3 pos);
    
private:
    
    bool addPhysics();
};

#endif /* defined(__Engine__GameObject__) */
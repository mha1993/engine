//
//  Marker.h
//  Engine
//
//  This is subclass of Ball and is used as a static marker, especially
//  for debugging.

#ifndef __Engine__Marker__
#define __Engine__Marker__

#include <iostream>
#include "Ball.h"

class Marker : Ball {
    
public:
    virtual void tick(float dt)override;
    Marker(glm::vec3 pos, glm::vec3 vel, float size, int idd);
};

#endif /* defined(__Engine__Marker__) */

//
//  SphereShape.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "SphereShape.h"


vec3 SphereShape::mSupport(vec3 dir){

    return vec3(0.0,0.0,0.0);
    
}



std::string SphereShape::getName(){

    return "sphere";
}

//
//  Object.cpp
//  Engine
//
//  Created by Mats Allen on 4/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Object.h"


Object::Object() {
	//test -- remove this line it <-----
}


void Object::setRenderer(Renderer* renderer){
    this->renderer = renderer;
}

Renderer* Object::getRenderer(){

    return renderer;
}

void Object::render() {
    renderer->Renderer::render();
}
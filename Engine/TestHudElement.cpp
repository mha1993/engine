//
//  TestHudElement.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "TestHudElement.h"

#include "Text.h"


void TestHudElement::render(){

    Text::draw("hazard.png", .9, .9, .1, .1);

}
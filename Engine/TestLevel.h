//
//  TestLevel.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-04.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__TestLevel__
#define __Engine__TestLevel__

#include <iostream>

#include "BaseLevel.h"


class TestLevel : public BaseLevel{

public:
    
    using BaseLevel::BaseLevel;
    
    void setup();
    
};

#endif /* defined(__Engine__TestLevel__) */

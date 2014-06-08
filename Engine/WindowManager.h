//
//  WindowManager.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-23.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__WindowManager__
#define __Engine__WindowManager__

#include <iostream>


class WindowManager{
    
    std::string lastString;
    
public:
    WindowManager();
    
    void init();
    void stop();
    void beforeRender();
    void afterRender();
    bool quitRequest();
    std::string readString();
    void poll();
};

#endif /* defined(__Engine__WindowManager__) */

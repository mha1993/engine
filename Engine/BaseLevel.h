//
//  BaseLevel.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-24.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__BaseLevel__
#define __Engine__BaseLevel__

#include <iostream>
#include <vector>
#include "GameObject.h"
#include "SceneManager.h"
#include "WindowManager.h"
#include "PE3.h"
#include "ECamera.h"

using namespace std;

class BaseLevel{
    
    //vector<GameObject *> gameObjects;
    SceneManager *sceneManager;
    WindowManager *windowManager;
    PE3 *physicsEngine;
    
    bool shouldBeRunning;
    

protected:
    ECamera *currentCamera;
    
public:
    
    BaseLevel(WindowManager *wm);
    int addObject(GameObject *go);
    virtual void setCurrentCamera(ECamera *camera);
    virtual ECamera *getCurrentCamera();
    virtual void run();
    virtual void setup();
    virtual void teardown();
    virtual void tick(float deltaTime);
    virtual void render();
    
};

#endif /* defined(__Engine__BaseLevel__) */
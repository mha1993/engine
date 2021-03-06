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
#include "Level.h"
#include "PE3.h"
#include "ECamera.h"

#include "HudRenderer.h"

using namespace std;

class BaseLevel : public Level{
    
    //vector<GameObject *> gameObjects;

    
protected:
    ECamera *currentCamera;
    SceneManager *sceneManager;
    PE3 *physicsEngine;
    HudRenderer *hudRenderer;
public:
    
    virtual void stop();
    
    BaseLevel(WindowManager *wm, HudRenderer * hd);
    int addObject(GameObject *go);
    GameObject* getObject(int idd);
    virtual void setCurrentCamera(ECamera *camera);
    virtual ECamera *getCurrentCamera();
    virtual void setup();
    virtual void teardown();
    virtual void tick(float deltaTime);
    virtual void render();
    
};

#endif /* defined(__Engine__BaseLevel__) */
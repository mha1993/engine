//
//  SceneManager.h
//  Engine
//
//  Created by Mats Allen on 5/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__SceneManager__
#define __Engine__SceneManager__

#include <iostream>
#include <vector>
#include "GameObject.h"
#include "PObject.h"
#include <map>

using namespace std;

class SceneManager {
    map<int, GameObject*> objects;
    
public:
    vector<PObject*> getPhysicsObjects();
    int addObject(GameObject *object);
    GameObject* getObject(int id);
    void removeObject(int id);
    SceneManager();
    
private:
    int idCounter;
};

#endif /* defined(__Engine__SceneManager__) */

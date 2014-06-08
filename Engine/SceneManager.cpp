//
//  SceneManager.cpp
//  Engine
//
//  Created by Mats Allen on 5/29/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "SceneManager.h"

vector<PObject*> SceneManager::getPhysicsObjects() {
    vector<PObject*> physicsObjects;
    map<int, GameObject*>::iterator it;
    for (it=objects.begin(); it!=objects.end(); ++it) {
        physicsObjects.push_back(it->second->getPhysicsObject());
    }
    return physicsObjects;
}

int SceneManager::addObject(GameObject *object){
    objects[object->objectId] = object;
    return object->objectId;
}

GameObject* SceneManager::getObject(int id) {
    if (objects.count(id))
        return objects.at(id);
    else
        return nullptr;
}

void SceneManager::removeObject(int id) {
    objects.erase(id);
}

SceneManager::SceneManager() {
    idCounter = 0;
}


vector<GameObject*> SceneManager::getObjects(){
    vector<GameObject*> gameObjects;
    map<int, GameObject*>::iterator it;
    for (it=objects.begin(); it!=objects.end(); ++it) {
        gameObjects.push_back(it->second);
    }
    return gameObjects;
}
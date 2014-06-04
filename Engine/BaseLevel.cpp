//
//  BaseLevel.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-24.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "BaseLevel.h"

#include "FPCamera.h"

#include <glm/gtc/matrix_transform.hpp>

BaseLevel::BaseLevel(WindowManager *wm){
    windowManager = wm;
    sceneManager = new SceneManager();
    physicsEngine = new PE3();
    currentCamera = new FPCamera();
    shouldBeRunning = false;
}

void BaseLevel::setup(){}
void BaseLevel::teardown(){}

void BaseLevel::run(){

    long double lastTime = time(0);
    
    while (shouldBeRunning) {
        
        long double newTime = time(0);
        float timeDiff = newTime - lastTime;
        lastTime = newTime;
        tick(timeDiff);
    }
}

void BaseLevel::render(){

    vector<GameObject *> gameObjects = sceneManager->getObjects();
    
    mat4 cameraMatrix = currentCamera->matrix();
    mat4 identityMatrix = mat4();
    
    windowManager->beforRender();
    for (int i=0; i<gameObjects.size(); ){
        GameObject *gameObject = gameObjects[i];
        Mesh *mesh = gameObject->getMesh();
        
        vec3 pos = gameObject->getPhysicsObject()->pos;
        mat4 uM = glm::translate(identityMatrix, pos);
        
        mesh->setMatrices(&uM,&cameraMatrix);
        mesh->draw();
    }
    windowManager->afterRender();


}
void BaseLevel::tick(float deltaTime){
    
    vector<PObject *> physicObjects = sceneManager->getPhysicsObjects();
    physicsEngine->tick(physicObjects, deltaTime);
    
    vector<Collision> collisions = physicsEngine->getCollisions();
    
    for (int i = 0 ; i<collisions.size(); i++){
    
        Collision col = collisions[i];
        
        GameObject *gameObject1 = sceneManager->getObject(col.obj1);
        GameObject *gameObject2 = sceneManager->getObject(col.obj2);
        
        gameObject1->collidedWith(gameObject2, col.norm , col.pos);
        gameObject2->collidedWith(gameObject2, col.norm , col.pos);
    }
    
    currentCamera->update(deltaTime);
    this->render();
}
int BaseLevel::addObject(GameObject *go){
    
    return sceneManager->addObject(go);
    
}

void BaseLevel::setCurrentCamera(ECamera *camera){
    currentCamera = camera;
}

ECamera *BaseLevel::getCurrentCamera(){
    return currentCamera;
}


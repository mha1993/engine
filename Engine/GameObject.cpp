//
//  GameObject.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-23.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "GameObject.h"


static int idCounter = 0;

GameObject::GameObject(int idd): objectId(idd){
    mesh = nullptr;
}
GameObject::GameObject(): objectId(idCounter++){
    mesh = nullptr;
}

void GameObject::tick(float tickTime){

    
}

PObject * GameObject::getPhysicsObject(){

    return nullptr;
    
}

void GameObject::collidedWith(GameObject *other, vec3 hitNormal, vec3 pos){

}

Mesh * GameObject::getMesh(){

    return mesh;
}
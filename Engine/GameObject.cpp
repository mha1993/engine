//
//  GameObject.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-23.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "GameObject.h"


GameObject::GameObject(int idd): objectId(idd){
    
}

void GameObject::tick(float tickTime){
    
}

PObject * GameObject::getPhysicsObject(){

    return physicsObject;
}

void GameObject::collidedWith(GameObject *other, vec3 hitNormal, vec3 pos){

}

Drawable * GameObject::getMesh(){

    return mesh;
}

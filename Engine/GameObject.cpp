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

}
GameObject::GameObject(): objectId(idCounter++){
    
}

void GameObject::tick(float tickTime){

    
}
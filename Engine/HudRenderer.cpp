//
//  HudRenderer.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-06.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "HudRenderer.h"



HudRenderer::HudRenderer(WindowManager *wm){
    windowManager = wm;
}

void HudRenderer::tick(float deltaT){
    
    for (int i = 0; i<elements.size(); i++){
    
        elements[i]->tick(deltaT);
        
    }
    
}

void HudRenderer::render(){

    for (int i = 0; i<elements.size(); i++) {
        
        elements[i]->render();
        
    }
}


void HudRenderer::addElement(HudElement * element){
    
    elements.push_back(element);
    
}
void HudRenderer::removeElement(HudElement * element){
    
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    
}
void HudRenderer::removeAllElements(){
    
    elements.clear();
    
}
//
//  ScoreKeeper.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-09.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "ScoreKeeper.h"
#include "Text.h"


ScoreKeeper::ScoreKeeper(){
}


void ScoreKeeper::render(){
    
    for (int i = 0; i<score.size(); i++) {
        
        string picture = "none";
        
        if (score[i]){
            picture = "golf_ball.png";
        }else{
            picture = "miss.png";
        }
        Text::draw(picture, -.95, .93f - i*.15f, .05f, .075f);
    }
    
}

void ScoreKeeper::miss(){

    score.push_back(0);
    
}

void ScoreKeeper::hit(){

    score.push_back(1);

}

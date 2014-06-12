//
//  LevelManager.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//



#include "LevelManager.h"

#include "CourseHole.h"

#include "HudRenderer.h"

#include "ScoreKeeper.h"

LevelManager::LevelManager(WindowManager *wm): Level(wm){}

Hole * LevelManager::last(){

    if (levels.size() < 1){
    
        std::cout << "ERROR: wrong formated file ";
        exit(EXIT_FAILURE);
    }
    return levels[levels.size()-1];
}

void LevelManager::setup(){
    vector<vector<string>> lines = FileReader::readFileToVectors("maps/course.db");
    
    HudRenderer *hudRenderer = new HudRenderer(windowManager);
    ScoreKeeper * sk = new ScoreKeeper();
    
    hudRenderer->addElement(sk);
    
    for (int i = 0; i<lines.size(); i++) {
        vector<string> line = lines[i];
        
        if (line.size() > 0 && line[0].compare(END_HOLE) != 0){
            string lineType = line[0];
            
            if (lineType.compare(COURSE) == 0){
                name = TextUtils::myconcat(line," ",1);
            }else if (lineType.compare(BEGIN_HOLE) == 0){
                levels.push_back(new CourseHole(windowManager,hudRenderer,sk));
            }else{
                last()->addLine(line);
            }
        }
    }
}

void LevelManager::run(){

    shouldBeRunning = true;

    current = 4;

    
    while (shouldBeRunning && current < levels.size()) {
        
        levels[current]->setup();
        levels[current]->run();
        
        while (windowManager->quitRequest()) {
            sleep(10);
            windowManager->poll();
        }
        
        //printf("ecape:%d\n",windowManager->quitRequest());
        levels[current]->teardown();
        current++;
    }

    
}
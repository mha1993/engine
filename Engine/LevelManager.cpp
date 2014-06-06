//
//  LevelManager.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "LevelManager.h"

#include "FileReader.h"

LevelManager::LevelManager(WindowManager *wm): Level(wm){}


void LevelManager::setup(){

    vector<vector<string>> lines = FileReader::readFileToVectors("maps/course.db");
    
    for (int i = 0; i<lines.size(); i++) {
        vector<string> line = lines[i];
        for (int j = 0; j<line.size(); j++) {
            printf("%s ",line[j].c_str());
        }
        printf("\n");
    }
}
//
//  FileReader.h
//  GameEngine
//
//  Created by Jakob Folkesson on 2014-04-15.
//  Copyright (c) 2014 Jakob Folkesson. All rights reserved.
//

#ifndef __GameEngine__FileReader__
#define __GameEngine__FileReader__

#include <iostream>
#include <string>


using namespace std;

class FileReader {
    string basepath;
public:
    FileReader();
    string readFile(string fileName);
    
};

#endif /* defined(__GameEngine__FileReader__) */

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

#include <vector>


using namespace std;

class FileReader {
    string basepath;
public:
    static string basePath();
    static vector<string> readFile(string fileName);
    static string readFileToString(string filename);
    static vector<vector<string>> readFileToVectors(string fileName);
    static string makePath(string file);
};

#endif /* defined(__GameEngine__FileReader__) */

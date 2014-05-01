//
//  FileReader.cpp
//  GameEngine
//
//  Created by Jakob Folkesson on 2014-04-15.
//  Copyright (c) 2014 Jakob Folkesson. All rights reserved.
//

#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>
#include <libgen.h>

#include "FileReader.h"

FileReader::FileReader() {
    string dir = dirname(__FILE__);
    basepath = dir;
}

string FileReader::readFile(string fileName) {
    string line;
    
    string buf = basepath + "/" + fileName;
    ifstream myfile(buf);
    if (myfile.is_open())
    {
        string file;
        while ( getline (myfile,line) )
        {
            file.append(line + "\n");
        }
        myfile.close();
        return file;
    }
    
    else cout << "Unable to open file " + buf + "\n";
    exit(EXIT_FAILURE);
    return nullptr;
}
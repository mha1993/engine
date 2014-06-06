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
#include <fstream>
#include <libgen.h>

#include "FileReader.h"

string FileReader::basePath() {
    return dirname(__FILE__);

}

vector<string> FileReader::readFile(string fileName) {
    string line;
    
    string buf = basePath() + "/" + fileName;
    ifstream myfile(buf);
    vector<string> strings;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            strings.push_back(line + "\n");
        }
    }else{
        cout << "Unable to open file " + buf + "\n";
        exit(EXIT_FAILURE);
        
    }
    return strings;
}


vector<vector<string>> FileReader::readFileToVectors(string fileName){

    vector<string> lines = FileReader::readFile(fileName);
    
    vector<vector<string>> ret;
    
    for (int i = 0; i<lines.size(); i++) {
        vector<string> vec;
        istringstream iss((lines[i]));
        copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(vec));
        ret.push_back(vec);
    }
    
    return ret;

}


string FileReader::readFileToString(string fileName) {
    string line;
    
    string buf = basePath() + "/" + fileName;
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

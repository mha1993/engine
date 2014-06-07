//
//  TextUtils.h
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#ifndef __Engine__TextUtils__
#define __Engine__TextUtils__

#include <iostream>

#include <string>
#include <vector>

using namespace std;

class TextUtils{

public:
    static string myconcat(vector<string> arr, string sep, int start);
};


#endif /* defined(__Engine__TextUtils__) */

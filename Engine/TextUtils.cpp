//
//  TextUtils.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-06-05.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "TextUtils.h"


string TextUtils::myconcat(vector<string> arr, string sep, int start){
    
    string s = "";
    
    for (int i=start; i<arr.size(); i++){
        
        s += arr[i];
        if (i+1<arr.size()){
            s += sep;
        }
    }
    return s;
}
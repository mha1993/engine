//
//  PolygonShape.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-24.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PolygonShape.h"

#include<limits>


PolygonShape::PolygonShape(vector<vec3> v){
    
    edges = v;
    
}

vec3 PolygonShape::mSupport(vec3 dir){
    
    float max = numeric_limits<float>::lowest();
    int index = 0;
    
    for (int i = 0; i < edges.size(); i++) {
        float dot = glm::dot(edges[i], dir);
        
        if (dot > max){
            max = dot;
            index = i;
        }
    }
    return edges[index];
}

vector<vec3> PolygonShape::getVerts() {
    return edges;
}
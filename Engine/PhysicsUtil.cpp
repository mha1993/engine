//
//  PhysicsUtil.cpp
//  Engine
//
//  Created by Jakob Folkesson on 2014-05-08.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "PhysicsUtil.h"

glm::vec3 calcNormal(glm::vec3 a, glm::vec3 b, glm::vec3 c) {

    
    b = b - a;
    c = c - a;
    
    glm::vec3 norm = glm::cross(b, c);
    norm = glm::normalize(norm);

    return norm;
    
}


// Discounts y axis
bool pointOnLineSeg(glm::vec3 v1, glm::vec3 v2, glm::vec3 point) {
    v1 -= point;
    v2 -= point;
    if (v2.x == v1.x)return (v2.z*v1.z < 0 && v2.x > 0);
    float slope = (v2-v1).z / (v2-v1).x;
    float m = v1.y - slope * v1.x;
    return (m*slope < 0);
}

bool pointInPoly(std::vector<glm::vec3> verts, glm::vec3 point) {
    int count = 0;
    for (int i=0; i<verts.size(); i++) {
        int i2 = i + 1;
        if (i2 == verts.size()) i2 = 0;
        if (pointOnLineSeg(verts[i], verts[i+1], point)) {
            count++;
        }
    }
    if (count%2 == 0) return false;
    else return true;
}
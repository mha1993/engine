//
//  DriverAI.cpp
//  Engine
//
//  Created by Mats Allen on 6/9/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "DriverAI.h"
#include "Tile.h"
#include "Graph.h"
#include "PolygonShape.h"
#include <algorithm>


void DriverAI::addWaypoint(vec3 wp) {
    waypoints.push_back(wp);
}

void DriverAI::calcWaypoints(SceneManager *sm, int idStart, int idEnd) {
    Graph graph;
    vector<GameObject*> objs = sm->getObjects();
    
    for (int i=0; i<objs.size(); i++) {
        if (objs[i]->identifier.compare("TILE") == 0) {
            Tile *tile = (Tile*)objs[i];
            cout << "SIZE: " << tile->getNeighbors().size() << endl;
            for (int j=0; j<tile->getNeighbors().size(); j++) {
                graph.addEdge(objs[i], sm->getObject(tile->getNeighbors()[j].first));
            }
        }
    }
    
    vector<int> path = graph.shortestPath(sm->getObject(idStart), sm->getObject(idEnd));
    
    for (int i=0; i<path.size(); i++) {
        Tile *t = (Tile*)sm->getObject(path[i]);
        vec3 waypoint = vec3();
        vector<vec3> verts = ((PolygonShape*)t->getPhysicsObject()->ps)->PolygonShape::getVerts();
        for (int j=0; j<verts.size(); j++) {
            waypoint += verts[0];
        }
        waypoint /= verts.size();
        waypoint += vec3(0,0.05,0);
        addWaypoint(waypoint);
    }
    reverse(waypoints.begin(),waypoints.end());
}

DriverAI::DriverAI(Ball *_ball, SceneManager *sm, int idStart, int idEnd) {
    ball = _ball;
    
    calcWaypoints(sm, idStart, idEnd);
    curWaypoint = 0;
}


void DriverAI::tick(float dt) {
    if (length(ball->getPhysicsObject()->pos - waypoints[curWaypoint]) < 0.05f) {
        curWaypoint++;
    }
    float speed = length(ball->getPhysicsObject()->vel);
    vec3 vel = 0.05f*normalize(waypoints[curWaypoint] - ball->getPhysicsObject()->pos);
    ball->getPhysicsObject()->vel += vel;
    if (length(ball->getPhysicsObject()->vel)>0.5)
        ball->getPhysicsObject()->vel = speed * normalize(ball->getPhysicsObject()->vel);
}

void DriverAI::showWaypoints(SceneManager *sm) {
    for (int i=0; i<waypoints.size(); i++) {
        Ball *b = new Ball(waypoints[i], vec3(), 0.1f, 9999999*i);
        sm->addObject(b);
    }
}

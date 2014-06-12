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
#include "Marker.h"


void DriverAI::addWaypoint(vec3 wp) {
    waypoints.push_back(wp);
}

/***************************************************************************
 ***************    Gets a list of tiles between tee and hole  *************
 **************************************************************************/
vector<int> getTilePath(SceneManager *sm, int idStart, int idEnd) {
    // Create graph
    Graph graph;
    // Get game objects from scene manager
    vector<GameObject*> objs = sm->getObjects();

    // Add the objects to a graph
    for (int i=0; i<objs.size(); i++) {
        if (objs[i]->identifier.compare("TILE") == 0) {
            Tile *tile = (Tile*)objs[i];
            cout << "TILE: " << tile->objectId << endl;
            for (int j=0; j<tile->getNeighbors().size(); j++) {
                cout << "    (" << objs[i]->objectId << ", " << sm->getObject(tile->getNeighbors()[j].first)->objectId << ")" << endl;
                graph.addEdge(objs[i], sm->getObject(tile->getNeighbors()[j].first));
            }
        }
    }
    
    // Get the shortest path
    vector<int> path = graph.shortestPath(sm->getObject(idStart), sm->getObject(idEnd));
    return path;
}

/***************************************************************************
 ***************      Converts list of tiles to waypoints      *************
 **************************************************************************/
vector<vec3> convertTilePathToEdgePath(SceneManager *sm, vector<int> tilePath) {
//    For each pair of consecutive tiles get the vertices of the edge
//    that joins them and place a waypoint at the center of the edge.
    
    
    vector<vec3> waypoints;
    cout << endl << "PATH LENGTH: " << tilePath.size() << endl;
    for (int i=0; i<tilePath.size()-1; i++) {
        Tile* t1 = (Tile*)sm->getObject(tilePath[i]);
        Tile* t2 = (Tile*)sm->getObject(tilePath[i+1]);
        cout << "T1 id: " << t1->objectId << "   T2 id: " << t2->objectId << endl;
        vector<vec3> verts = ((PolygonShape*)t1->getPhysicsObject()->ps)->PolygonShape::getVerts();
        
        int edgeIndex = -9999;
        vector<pair<int, int>> edges = t1->getNeighbors();
        for (int j=0; j<edges.size(); j++) {
            int idd = edges[j].first;
            if (idd == t2->objectId) {
                edgeIndex = edges[j].second;
                break;
            }
        }
        if (edgeIndex == -9999) {
            cout << "SOMETHING WENT WRONG" << endl;
            exit(-9999);
        } else {
            vec3 v1 = verts[edgeIndex];
            vec3 v2 = verts[edgeIndex+1];
            
            vec3 waypoint = (v1 + v2) / 2.0f;
            
            waypoints.push_back(waypoint);
        }
    }
    reverse(waypoints.begin(),waypoints.end());
    return waypoints;
}


/***************************************************************************
 ***************          Calculates waypoints for AI          *************
 **************************************************************************/
void DriverAI::calcWaypoints(SceneManager *sm, int idStart, int idEnd) {
    //Get list of tiles that will be crossed
    vector<int> tilePath = getTilePath(sm, idStart, idEnd);
    
    //Create waypoint at the edges where one tiles meets the next
    waypoints.clear();
    waypoints = convertTilePathToEdgePath(sm, tilePath);
}

/***************************************************************************
 ***************                  Constructor                  *************
 **************************************************************************/
DriverAI::DriverAI(Ball *_ball, SceneManager *sm, int idStart, int idEnd, int idHole) {
    ball = _ball;
    calcWaypoints(sm, idStart, idEnd);
    waypoints.push_back(sm->getObject(idHole)->getPhysicsObject()->pos);
    curWaypoint = 0;
}

/***************************************************************************
 *************** Update function. Gets called every game cycle *************
 **************************************************************************/
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


/***************************************************************************
 *********** Testing function. Draws green balls for each waypoint *********
 **************************************************************************/
void DriverAI::showWaypoints(SceneManager *sm) {
    for (int i=0; i<waypoints.size(); i++) {
        Marker *m = new Marker(waypoints[i], vec3(), 0.1f, 9999999*i);
        sm->addObject((GameObject*)m);
    }
}

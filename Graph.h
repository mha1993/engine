//
//  Graph.h
//  Engine
//
//  Custom graph type for calculating path for AI
//

#ifndef __Engine__Graph__
#define __Engine__Graph__

#include <iostream>
#include <map>
#include <vector>
#include "GameObject.h"

using namespace std;

class Graph {
    map<int, vector<GameObject*>> lists;
    
    
public:
    void addNode(GameObject* node);
    void addEdge(GameObject* n1, GameObject* n2);
    vector<GameObject*> getAdjacentNodes(GameObject* node);
    vector<int> shortestPath(GameObject* start, GameObject* end);
    bool shortestPathIt(map<int, bool> visited, GameObject* start, GameObject* end, int i, bool found, vector<int> *path);
};

#endif /* defined(__Engine__Graph__) */

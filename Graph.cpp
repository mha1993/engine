//
//  Graph.cpp
//  Engine
//
//  Created by Mats Allen on 6/10/14.
//  Copyright (c) 2014 MHA. All rights reserved.
//

#include "Graph.h"


void Graph::addNode(GameObject* node) {
    if (lists.find(node->objectId) == lists.end()) {
        vector<GameObject*> list;
        lists[node->objectId] = list;
    }
}

void Graph::addEdge(GameObject* n1, GameObject* n2) {
    addNode(n1);
    addNode(n2);
    typename map<int, vector<GameObject*>>::iterator it;
    it = lists.find(n1->objectId);
    it->second.push_back(n2);
}

vector<GameObject*> Graph::getAdjacentNodes(GameObject* node) {
    return lists.find(node->objectId)->second;
}

bool Graph::shortestPathIt(map<int, bool> visited, GameObject* start, GameObject* end, int i, bool found, vector<int> *path) {
    visited[start->objectId] = true;
    i++;
    if (start->objectId != end->objectId) {
        vector<GameObject*> adj = lists.find(start->objectId)->second;
        for (int j=0; j<adj.size(); j++) {
            if (!visited[adj[j]->objectId]) {
                found = found ? found : shortestPathIt(visited, adj[j], end, i, found, path);
            }
        }
    } else {
        found = true;
    }
    if (found) {
        path->push_back(start->objectId);
    }
    return found;
}

vector<int> Graph::shortestPath(GameObject* start, GameObject* end) {
    map<int, bool> visited;
    vector<int> path;
    shortestPathIt(visited, start, end, 0, false, &path);
    return path;
}







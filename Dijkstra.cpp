/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dijkstra.cpp
 * Author: Raell
 * 
 * Created on May 18, 2018, 11:38 PM
 */

#include "Dijkstra.h"
#include <algorithm>

using namespace std;

// Constructor storing start node, end node and graph
Dijkstra::Dijkstra(unsigned s, unsigned e, const Graph& g) {
    start = s;
    end = e;
    graph = g;
}

// Output shortest path and distance from spanning tree
string Dijkstra::getShortestPath() {
    // Generate spanning tree from start node
    Graph spanningTree = getSpanningTreeFromStart();
    unsigned current = end;

    float value = 0.0;
    string path = to_string(end);
   
    // Starting from end node, follow edges to start node
    while(!spanningTree.getEdgesFrom(current).empty()) {
        // Edges at the back are the shortest path
        Edge e = spanningTree.getEdgesFrom(current).back();
        value += e.getWeight();
        path = to_string(e.getDestination()) + " -> " + path;
        current = e.getDestination();
    }
    
    return "Distance: " + to_string(value) + "\r\nRoute:\r\n" + path;
}

// Generates a spanning tree graph from starting node
Graph Dijkstra::getSpanningTreeFromStart() {
    //Initialize unvisited nodes and spanning tree
    vector<unsigned> unvisited;
    Graph result = Graph();
    
    // Set start node as first node to process and the rest to be visited
    Node *currentNode = graph.getNode(start);
    currentNode->setDistance(0.0);
    for(auto n : graph.getNodes()) {
        if(n.getIndex() != start) {
            unvisited.push_back(n.getIndex());
        }
    }
    
    // Initial update distance to neighbors of start node
    updateDistances(unvisited, currentNode, result);
    
    // Replace current node with next unvisited node and update distances
    while(!unvisited.empty()) {
        // Sort unvisited nodes so that closer nodes are visited first
        sort(unvisited.begin(), unvisited.end(), 
            [this](unsigned lhs, unsigned rhs)
            {return this->graph.getNode(lhs)->getDistance() < this->graph.getNode(rhs)->getDistance();}
        );
        currentNode = graph.getNode(unvisited.front());
        unvisited.erase(unvisited.begin());
        updateDistances(unvisited, currentNode, result);
    }
    
    return result;
    
}

// Updates distances of node to starting node
void Dijkstra::updateDistances(vector<unsigned> unvisited, Node *currentNode, Graph& result) {
    // Loop through all neighbors of current node
    for(auto e: graph.getEdgesFrom(currentNode->getIndex())) {
        
        Node *neighbor = graph.getNode(e.getDestination());
        auto it = find_if(unvisited.begin(), 
                          unvisited.end(), 
                          [neighbor](Node n){return n.getIndex() == neighbor->getIndex();}
                          ); 
        // Only updates neighbor if not already visited                  
        if(it != unvisited.end()) {
            float distance = neighbor->getDistance();
            float possibleUpdate = min(distance, currentNode->getDistance() + e.getWeight());
            
            //Update new distance if shorter and adds new edge to spanning tree
            if(distance > possibleUpdate) {
                neighbor->setDistance(possibleUpdate);
                result.addEdge(Edge(neighbor->getIndex(), currentNode->getIndex(), e.getWeight()));
            }
        }
    }
}



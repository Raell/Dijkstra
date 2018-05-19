/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.cpp
 * Author: Raell
 * 
 * Created on May 18, 2018, 6:31 PM
 */

#include "Graph.h"
#include <algorithm>

using namespace std;

Graph::Graph() {
}

// Add nodes to graph from 0 to n-1
void Graph::addNodes(unsigned n) {
    for(int i = 0; i < n; i++) {
        nodes.push_back(Node(i));
    }
}

// Return reference to specified node
Node* Graph::getNode(unsigned index) {
    return &nodes[index];
}

// Returns all nodes
vector<Node> Graph::getNodes() {
    return nodes;
}

// Adds an Edge to graph
void Graph::addEdge(const Edge& edge) {
    edges.push_back(edge);
}

// Return all edges
vector<Edge> Graph::getEdges() {
    return edges;
}

// Return all edges with source specified
vector<Edge> Graph::getEdgesFrom(unsigned source) {
    vector<Edge> edgesFrom;
    auto lambda = [source](Edge e){return e.getSource() == source;};
    auto it = copy_if(edges.begin(), edges.end(),
                           back_inserter(edgesFrom), 
                           lambda
                           );
    return edgesFrom;                                                  
}

// Return all edges with destination specified
vector<Edge> Graph::getEdgesTo(unsigned destination) {
    vector<Edge> edgesTo;
    auto lambda = [destination](Edge e){return e.getDestination() == destination;};
    auto it = copy_if(edges.begin(), edges.end(),
                           back_inserter(edgesTo), 
                           lambda
                           );
    return edgesTo;   
}



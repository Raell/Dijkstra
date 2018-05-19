/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: Raell
 *
 * Created on May 18, 2018, 6:31 PM
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "Node.h"
#include <vector>

class Graph {
public:
    Graph();
    void addNodes(unsigned n);
    void addEdge(const Edge& edge);
    Node* getNode(unsigned index);
    std::vector<Node> getNodes();
    std::vector<Edge> getEdges();
    std::vector<Edge> getEdgesFrom(unsigned source);
    std::vector<Edge> getEdgesTo(unsigned destination);
private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;
};

#endif /* GRAPH_H */


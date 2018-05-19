/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dijkstra.h
 * Author: Raell
 *
 * Created on May 18, 2018, 11:38 PM
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include <vector>
#include <string>

class Dijkstra {
public:
    Dijkstra(unsigned s, unsigned e, const Graph& g);
    std::string getShortestPath();
private:
    unsigned start;
    unsigned end;
    Graph graph;
    void updateDistances(std::vector<unsigned> unvisited, Node *currentNode, Graph& result);
    Graph getSpanningTreeFromStart();
};

#endif /* DIJKSTRA_H */


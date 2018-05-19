/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edge.cpp
 * Author: Raell
 * 
 * Created on May 18, 2018, 6:47 PM
 */

#include "Edge.h"

// Edge object containing source, destination and weight
Edge::Edge(unsigned s, unsigned d, float w) {
    source = s;
    destination = d;
    weight = w;
}

// Returns source of edge
unsigned Edge::getSource() const {
    return source;
}

// Returns destination of edge
unsigned Edge::getDestination() const {
    return destination;
}

// Returns weight of edge
float Edge::getWeight() const {
    return weight;
}

// Returns new Edge with swapped source and destination
Edge Edge::swap() {
    return Edge(destination, source, weight);
}


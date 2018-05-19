/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: Raell
 * 
 * Created on May 19, 2018, 12:58 AM
 */

#include <limits>
#include "Node.h"

// Node object with distance to start default to infinity
Node::Node(unsigned n) {
    index = n;
    distance = std::numeric_limits<float>::infinity();
}

// Return index of node
unsigned Node::getIndex() const {
    return index;
}

// Return distance to start node
float Node::getDistance() const {
    return distance;
}

// Set distance of node
void Node::setDistance(float d) {
    distance = d;
}



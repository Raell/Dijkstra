/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edge.h
 * Author: Raell
 *
 * Created on May 18, 2018, 6:47 PM
 */

#ifndef EDGE_H
#define EDGE_H

class Edge {
public:
    Edge(unsigned s, unsigned d, float w);
    unsigned getSource() const;
    unsigned getDestination() const;
    float getWeight() const;
    Edge swap();
private:
    unsigned source;
    unsigned destination;
    float weight;
};

#endif /* EDGE_H */


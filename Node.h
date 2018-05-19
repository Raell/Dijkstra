/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Raell
 *
 * Created on May 19, 2018, 12:58 AM
 */

#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(unsigned n);
    unsigned getIndex() const;
    float getDistance() const;
    void setDistance(float d);
private:
    unsigned index;
    float distance; 
};

#endif /* NODE_H */


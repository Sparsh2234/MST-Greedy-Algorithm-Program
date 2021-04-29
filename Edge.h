//
// Created by Sparsh on 4/10/2021.
//

#ifndef PROJECT3_EDGE_H
#define PROJECT3_EDGE_H

#include "Vertex.h"

class Edge {

private:
    double weight;
    Vertex * u;
    Vertex * v;

public:
    Edge(double weight, Vertex * u, Vertex * v);
    Edge();

    double getWeight();
    void setWeight(double weight);
    Vertex * getV();
    Vertex * getU();

};


#endif //PROJECT3_EDGE_H

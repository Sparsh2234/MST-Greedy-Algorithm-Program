//
// Created by Sparsh on 4/10/2021.
//

#include "Edge.h"

Edge::Edge(double weight, Vertex *u, Vertex *v) {
    this->weight = weight;
    this->u = u;
    this->v = v;
}

double Edge::getWeight() {
    return weight;
}

void Edge::setWeight(double weight) {
    this->weight = weight;
}

Vertex * Edge::getU() {
    return u;
}

Vertex * Edge::getV() {
    return v;
}
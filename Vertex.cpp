//
// Created by Sparsh on 4/10/2021.
//

#include "Vertex.h"
#include <iostream>
Vertex::Vertex(Vertex * parent, int index) {
    this->parent = parent;
    this->index = index;
    this->degree = 0;
}

Vertex::Vertex() {
    this->parent = nullptr;
}

int Vertex::getIndex() {
    return index;
}

void Vertex::addDegree() {
    this->degree = degree + 1;
}

void Vertex::removeDegree() {
    this->degree = degree-1;
}

int Vertex::getDegree() {
    return degree;
}

void Vertex::setKey(double key) {
    this->key = key;
}

void Vertex::setParent(Vertex *parent) {
    this->parent = parent;
}

double Vertex::getKey() {
    return key;
}

void Vertex::setTempWeight(double temp) {
    this->tempWeight = temp;
}

double Vertex::getTempWeight() {
    return this->tempWeight;
}
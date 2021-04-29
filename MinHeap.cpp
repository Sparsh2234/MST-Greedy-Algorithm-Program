//
// Created by Sparsh on 4/11/2021.
//

#include <iostream>
#include "MinHeap.h"
#include "Graph.h"

using namespace std;
Graph g;

MinHeap::MinHeap(int heapSize) {
    this->minHeap = new int [heapSize];
    this->heapIndex = heapSize;
}


void MinHeap::init() {

    for (int i = 0; i < g.getAdjListSize(); i++) {;
        minHeap[i] = g.getVertexNum(i);
    }

    heapIndex = g.getAdjListSize();
}


void MinHeap::modifyKey(int vertex) {

    Vertex * vert = g.getVertex(vertex);
    int vertPosition = findVertex(vertex);

    int i = vertPosition;

    while (i > 0 && getParentVertex(i)->getKey() > vert->getKey()) {

        minHeap[i] = getParent(i);
        i = ((i-1)/2);
        minHeap[i] = vertex;
    }
}

int MinHeap::findVertex(int vertex) {
    for (int i = 0; i < heapIndex; i++) {

        //cout<<minHeap[i]<<endl;
        if (minHeap[i] == vertex)
        {
            return i;
        }
    }
    return NULL;
}


void MinHeap::heapify(int index) {   // 0 is the head not 1
    int smallest = index;
    int left  = 2 * index +1;
    int right = 2 * index + 2;

    if (left < heapIndex && g.getVertex(minHeap[left])->getKey() < g.getVertex(minHeap[smallest])->getKey()) {
        smallest = left;
    }

    if (right < heapIndex && g.getVertex(minHeap[right])->getKey() < g.getVertex(minHeap[smallest])->getKey()) {
        smallest = right;
    }

    if (smallest != index) {
        int temp1 = minHeap[index];
        int temp2 = minHeap[smallest];
        minHeap[smallest] = temp1;
        minHeap[index] = temp2;
        heapify(smallest);
    }
}

int MinHeap::extractMin() {
    int min = minHeap[0];
    minHeap[0] = minHeap[heapIndex-1];
    heapIndex = heapIndex - 1;
    heapify(0);
    return min;

}

int MinHeap::getParent(int i) {
    return minHeap[(i-1)/2];
}

Vertex * MinHeap::getParentVertex(int i) {
    return g.getVertex(minHeap[((i-1)/2)]);
}

int MinHeap::getHeapSize() {
    return heapIndex;
}
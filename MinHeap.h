//
// Created by Sparsh on 4/11/2021.
//

#ifndef PROJECT3_MINHEAP_H
#define PROJECT3_MINHEAP_H


#include "Vertex.h"

class MinHeap {

private:

    int * minHeap;
    int heapIndex;


    int getParent(int i);
    Vertex * getParentVertex(int i);
    int findVertex(int vertex);


public:

    MinHeap(int heapSize);

//    void insertVertex(int vertex);
    void modifyKey(int vertex);
    void heapify(int index);
    int extractMin();
    void init();
    int getHeapSize();
    void insertVertex(int vertex);



};


#endif //PROJECT3_MINHEAP_H

 //
// Created by Sparsh on 4/10/2021.
//

#ifndef PROJECT3_GRAPH_H
#define PROJECT3_GRAPH_H

using namespace std;

#include <vector>

#include "Vertex.h"
#include "Edge.h"

 class Graph {

 private:

     Edge *** edgeMatrix;
     int totalNumEdges = 0;
     int edgeMatrixSize = 0;

 public:
    void createGraph(int m);
    void createEdgeList(int m);
    void insertEdge(int u, int v, double weight);
    bool eraseEdge(int u, int v);
    bool isAdjacent(int u, int v, double weight);
    int edgeCount();
    void clear();
    double mst(int u);
    Vertex * getVertex(int index);
    int getAdjListSize();
    int getVertexNum(int i);
    int getAdjVertexNum(int i, int j);
    int getNodeDegree(int i);

    //debug

    double getEdgeWeight(int u, int v);


};


#endif //PROJECT3_GRAPH_H

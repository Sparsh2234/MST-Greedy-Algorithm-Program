//
// Created by Sparsh on 4/10/2021.
//
using namespace std;

#include <iostream>
#include <vector>

#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include "MinHeap.h"

int adjListSize;
vector<vector<Vertex*>> adjList;


void Graph::createGraph(int m) {

    edgeMatrixSize = m;

    for (int i = 0; i < m; i++) {
        vector<Vertex*> list;
        adjList.push_back(list);
    }

    for (int i = 0; i < adjList.size(); i++) {
        Vertex * temp1 = new Vertex(nullptr, i);
        adjList[i].push_back(temp1);
    }

    createEdgeList(m);
}

void Graph::createEdgeList(int m) {

    edgeMatrix = new Edge** [m];

    for (int i = 0; i< m; i++) {
        edgeMatrix[i] = new Edge*[m];
        for (int r = 0; r < m; r++) {
            edgeMatrix[i][r] = nullptr;
        }
    }
}

void Graph::insertEdge(int u, int v, double weight) {

    bool elseEntered = false;

    Vertex* vert1 = new Vertex(nullptr, u);
    Vertex* vert2 = new Vertex(nullptr, v);

    if (edgeMatrix[u][v] == nullptr) {
        Edge* edge = new Edge(weight, vert1, vert2);
        edgeMatrix[u][v] = edge;
        edgeMatrix[v][u] = edge;
        //vert2->degree++;
        //vert1->degree++;
        totalNumEdges++;
    } else {
        edgeMatrix[u][v]->setWeight(weight);
        elseEntered = true;
    }

    if (elseEntered == false) {
        bool doesContain = false;
        for (int i = 0; i < adjList[u].size(); i++) {
            if (adjList[u][i] == vert2) {
                doesContain = true;
            }
        }

        if (doesContain == false) {
            adjList[u].emplace_back(vert2);
            adjList[u][0]->degree++;
        }

        doesContain = false;
        for (int i = 0; i < adjList[v].size(); i++) {
            if (adjList[v][i] == vert1) {
                doesContain = true;
            }
        }

        if (doesContain == false) {
            adjList[v].emplace_back(vert1);
            adjList[v][0]->degree++;
        }

    }

}

bool Graph::eraseEdge(int u, int v) {

    if (edgeMatrix[u][v] != nullptr) {
        edgeMatrix[u][v] = nullptr;
        adjList[u][0]->removeDegree();
        adjList[v][0]->removeDegree();

        int indexU = 0;
        int indexV = 0;



        for (int i =0; i < adjList[u].size(); i++) {
            if (adjList[u][i]->getIndex() == v) {
                indexV = i;
                break;
            }
        }

        for (int i =0; i < adjList[v].size(); i++) {
            if (adjList[v][i]->getIndex() == u) {
                indexU = i;
                break;
            }
        }

        vector<Vertex*>::iterator uIt;
        vector<Vertex*>::iterator vIt;

        uIt = ((adjList[v].begin() + indexU));
        vIt = ((adjList[u].begin() + indexV));

        adjList[u].erase(vIt);
        adjList[v].erase(uIt);


        totalNumEdges--;
        return true;
    } else {
        return false;
    }
}

bool Graph::isAdjacent(int u, int v, double weight) {
    if (edgeMatrix[u][v] != nullptr) {
        if (edgeMatrix[u][v]->getWeight() == weight) {
            return true;
        }
    } else {
        return false;
    }
}

int Graph::edgeCount() {
    return totalNumEdges*2;
}

void Graph::clear() {
    for (int i = 0; i<edgeMatrixSize; i++) {;
        for (int r = 0; r < edgeMatrixSize; r++) {
            edgeMatrix[i][r] = nullptr;
        }
    }

    for (int i = 0; i<adjList.size(); i++) {;
        for (int r = 0; r < adjList[i].size(); r++) {
            adjList[i][r]->degree = 0;
            adjList[i].pop_back();
        }
    }
    totalNumEdges = 0;

}

double Graph::mst(int u) {

    double weight = 0;

    adjListSize = adjList.size();

    MinHeap heap = MinHeap(adjList.size());

    Vertex * root = adjList[u][0];

    //heap->modifyKey(u);

    for (int i = 0; i < adjList.size(); i++) {
        adjList[i][0]->setKey(2147483647);
        adjList[i][0]->setParent(nullptr);
    }
    heap.init();

    root->setKey(0);
    heap.modifyKey(root->getIndex());


    while (heap.getHeapSize() > 0) {

        int u = heap.extractMin();
        weight = weight + getVertex(u)->getKey();


        Vertex * vertU = getVertex(u);

        for (int i = 1; i < adjList[u].size(); i++) {

            int v = getAdjVertexNum(u, i);
            Vertex * vertV = getVertex(v);

            if (edgeMatrix[u][v]->getWeight() == 2147483647) {
                return 0;
            }

            if (v != u && edgeMatrix[u][v]->getWeight() < vertV->getKey()) {
                vertV->setKey(edgeMatrix[u][v]->getWeight());
                heap.modifyKey(v);
                vertV->setParent(vertU);
            }

        }
    }


    return weight;

}

Vertex * Graph::getVertex(int index) {
    return adjList[index][0];
}

int Graph::getAdjListSize() {
    return adjListSize;
}

int Graph::getVertexNum(int i) {
    return adjList[i][0]->getIndex();
}

int Graph::getAdjVertexNum(int i, int j) {
    return adjList[i][j]->getIndex();
}


double Graph::getEdgeWeight(int u, int v) {
    return edgeMatrix[u][v]->getWeight();
}

int Graph::getNodeDegree(int i) {
   return adjList[i][0]->degree;
}
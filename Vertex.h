//
// Created by Sparsh on 4/10/2021.
//

#ifndef PROJECT3_VERTEX_H
#define PROJECT3_VERTEX_H


class Vertex {

    friend class Graph;

private:

    Vertex * parent;
    int index;

    double key = 0;
    double tempWeight = 0;
    int degree;


public:

    Vertex(Vertex * parent, int index);
    Vertex();

    void setParent(Vertex * parent);
    void setKey(double key);
    void setTempWeight(double temp);
    double getTempWeight();
    double getKey();
    int getIndex();
    int getDegree();
    void addDegree();
    void removeDegree();


};


#endif //PROJECT3_VERTEX_H

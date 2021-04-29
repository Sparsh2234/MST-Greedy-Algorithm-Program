#include <iostream>
#include "Graph.h"
#include "MinHeap.h"
#include "illegal_exception.h"
#include <iomanip>
int main() {

    std::string line;
    Graph g;
    bool error;

    while (true) {

        if (cin.eof()) {
            break;
        }

        getline(cin, line);

        if (line == "exit") {
            break;
        }

        int pos = line.find(" ");
        std::string cmd = line.substr(0, pos);
        std::string obj = line.substr(pos + 1);

        if (cmd == "n") {
            pos = obj.find(" ");
            int graphSize = stoi(obj.substr(0, pos));
            g.createGraph(graphSize);
            cout << "success" << endl;
        }

        if (cmd == "i") {
            pos = obj.find(";");
            int u = stoi(obj.substr(0, pos));
            obj = obj.substr(pos + 1);
            pos = obj.find(";");
            int v = stoi(obj.substr(0, pos));
            obj = obj.substr(pos + 1);
            pos = obj.find(" ");
            double w = stod(obj.substr(0, pos));
            bool isIllegal = false;

            try {
                if (u == v || u < 0 || v < 0 || w < 0.0) {
                    isIllegal = true;
                    throw illegal_exception();
                }
            } catch (illegal_exception p) {
                cout<<"illegal argument"<<endl;
            }

            if (!isIllegal) {
                g.insertEdge(u,v,w);
                cout<< "success" <<endl;
            }

        }

        if (cmd == "e") {
            pos = obj.find(";");
            int u = stoi(obj.substr(0, pos));
            obj = obj.substr(pos + 1);
            pos = obj.find(" ");
            int v = stoi(obj.substr(0, pos));
            bool isIllegal = false;

            try {
                if (u == v || u < 0 || v < 0 ) {
                    isIllegal = true;
                    throw illegal_exception();
                }
            } catch (illegal_exception p) {
                cout<<"illegal argument"<<endl;
            }

            if (!isIllegal) {
                error = g.eraseEdge(u,v);
                if (error) {
                    cout << "success" <<endl;
                } else {
                    cout << "failure" <<endl;
                }
            }
        }

        if (cmd == "adjacent") {
            pos = obj.find(";");
            int u = stoi(obj.substr(0, pos));
            obj = obj.substr(pos + 1);
            pos = obj.find(";");
            int v = stoi(obj.substr(0, pos));
            obj = obj.substr(pos + 1);
            pos = obj.find(" ");
            double w = stod(obj.substr(0, pos));
            bool isIllegal = false;

            try {
                if (u == v || u < 0 || v < 0 || w < 0.0) {
                    isIllegal = true;
                    throw illegal_exception();
                }
            } catch (illegal_exception p) {
                cout<<"illegal argument"<<endl;
            }

            if (!isIllegal) {
                error = g.isAdjacent(u,v,w);

                if (error) {
                    cout << "adjacent ";
                    cout<<u;
                    cout<<" ";
                    cout<<v;
                    cout<<" ";
                    cout << std::fixed << std::setprecision(2) <<w;
                    cout<<endl;
                } else {
                    cout << "not adjacent ";
                    cout<<u;
                    cout<<" ";
                    cout<<v;
                    cout<<" ";
                    cout << std::fixed << std::setprecision(2) <<w;
                    cout<<endl;
                }
            }
        }

        if (cmd == "degree") {
            pos = obj.find(" ");
            int u = stoi(obj.substr(0, pos));
            bool isIllegal = false;
            try {
                if ( u < 0 ) {
                    isIllegal = true;
                    throw illegal_exception();
                }
            } catch (illegal_exception p) {
                cout<<"illegal argument"<<endl;
            }

            if(!isIllegal) {
                int degree = g.getNodeDegree(u);
                cout<<"degree of ";
                cout<<u;
                cout<<" is ";
                cout<<degree<<endl;
            }

        }

        if (cmd == "edge_count") {
            cout<<"edge count is ";
            cout<<g.edgeCount()<<endl;
        }

        if (cmd == "clear") {
            g.clear();
            cout<<"success"<<endl;
        }

        if (cmd == "mst") {
            pos = obj.find(" ");
            int u = stoi(obj.substr(0, pos));

            bool isIllegal = false;
            try {
                if ( u < 0 ) {
                    isIllegal = true;
                    throw illegal_exception();
                }
            } catch (illegal_exception p) {
                cout<<"illegal argument"<<endl;
            }

            if(!isIllegal) {
                double er = g.mst(u);

                if (er == 0) {
                    cout << "not connected" << endl;
                } else {
                    cout <<"mst ";
                    cout << std::fixed << std::setprecision(2) <<er << std::endl;
                }
            }

        }

    }

    return 0;
}

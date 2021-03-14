#include "Graph.h"
#include "link.h"
#include "list.h"
#include "llist.h"
#include <bits/stdc++.h>
#ifndef GRAPHL
#define GRAPHL
using namespace std;

class Edge {
  private:
    int vert;
    int weight;

  public:
    Edge() {
        vert = -1;
        weight = -1005;
    }
    Edge(int v, int w) {
        vert = v;
        weight = w;
    }
    ~Edge(){};
    int getVertex() { return vert; }
    int getWeight() { return weight; }
};

ostream &operator<<(ostream &s, Edge e) {
    return s << '(' << e.getVertex() << ", " << e.getWeight() << ')';
}

template <typename E> class Graphl : public Graph<E> {
  private:
    int numVertex, numEdge;
    LList<Edge> **adjlist;
    int *mark;
    int **matrix; // 用来记录两点间权值
    bool isDirected;
    E *vertex;

  public:
    Graphl(int n) { Init(n); }
    ~Graphl() {
    }
    void Init(int n) {
        numVertex = n;
        numEdge = 0;
        mark = new int[n];
        vertex = new E[n];
        matrix = (int **)new int*[numVertex]; // Make matrix
        for (int i = 0; i < numVertex; i++) {
            matrix[i] = new int[numVertex];
        }
        adjlist = (LList<Edge> **)new LList<Edge> *[n];
        for (int i = 0; i < n; i++) {
            adjlist[i] = new LList<Edge>();
            mark[i] = 0;
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    int getnumEdge() { return numEdge; }
    int getnumVertex() { return numVertex; }
    int first(int v) {
        assert(v < numVertex);
        if (adjlist[v]->length() == 0) {
            return numVertex;
        }
        adjlist[v]->moveToStart();
        Edge temp = adjlist[v]->getValue();
        return temp.getVertex();
    }
    int next(int v, int w) {
        assert(w < numVertex - 1 && isEdge(v, w));
        adjlist[v]->next();
        Edge temp = adjlist[v]->getValue();
        return temp.getVertex();
    }
    void setType(int flag) {
        if (flag == 1) {
            isDirected = true;
        } else {
            isDirected = false;
        }
    }
    bool getType() { return isDirected; }
    int locateVex(E u) {
        for (int i = 0; i < numVertex; i++) {
            if (u == vertex[i]) {
                return i;
            }
        }
        return -1;
    }
    E getVex(int v) { return vertex[v]; }
    void setVex(int v, E value) {
        assert(v < numVertex);
        vertex[v] = value;
    }
    void setEdge(int v1, int v2, int wght) {
        assert(v1 < numVertex && v2 < numVertex);
        Edge temp(v2, wght);
        if (isEdge(v1, v2)) {
            adjlist[v1]->remove();
            adjlist[v1]->insert(temp);
            matrix[v1][v2] = wght;
        } else {
            numEdge++;
            for (adjlist[v1]->moveToStart();
                 adjlist[v1]->currPos() < adjlist[v1]->length();
                 adjlist[v1]->next()) {
                Edge temp2 = adjlist[v1]->getValue();
                if (temp2.getVertex() > v2) {
                    break;
                }
            }
            adjlist[v1]->insert(temp);
            matrix[v1][v2] = wght;
            if (!isDirected) {
                Edge temp1(v1, wght);
                for (adjlist[v2]->moveToStart();
                     adjlist[v2]->currPos() < adjlist[v2]->length();
                     adjlist[v2]->next()) {
                    Edge temp2 = adjlist[v2]->getValue();
                    if (temp2.getVertex() > v1) {
                        break;
                    }
                }
                adjlist[v2]->insert(temp1);
            }
        }
    }
    void delEdge(int v1, int v2) {
        assert(v1 < numVertex && v2 < numVertex);
        if (isEdge(v1, v2)) {
            adjlist[v1]->remove();
            numEdge--;
            matrix[v1][v2] = 0;
            if (!isDirected) {
                adjlist[v2]->remove();
                numEdge--;
                matrix[v2][v1] = 0;
            }
        }
    }
    bool isEdge(int v, int w) {
        for (adjlist[v]->moveToStart();
             adjlist[v]->currPos() < adjlist[v]->length(); adjlist[v]->next()) {
            Edge temp = adjlist[v]->getValue();
            if (temp.getVertex() == w) {
                return true;
            }
        }
        return false;
    }
    int getWeight(int v, int w) {
        assert(isEdge(v, w));
        Edge temp;
        if (isEdge(v, w)) {
            temp = adjlist[v]->getValue();
            return temp.getWeight();
        }
        return 0;
    }
    void setMark(int v, E value) { mark[v] = value; }
    E getMark(int v) { return mark[v]; }

    void printweight() {
        for (int i = 0; i < numVertex; i++) {
            for (adjlist[i]->moveToStart();
                 adjlist[i]->currPos() < adjlist[i]->length();
                 adjlist[i]->next()) {
                cout << adjlist[i]->getValue() << ' ';
            }
            cout << endl;
        }
    }
    void printMatrix() {
        for (int i = 0; i < numVertex; i++) {
            for (int j = 0; j < numVertex; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }
    void printMax() {
        char tempE;
        int maxtemp = 0;
        for (int i = 0; i < numVertex; i++) {
            int temp = 0;
            for (int j = 0; j < numVertex; j++) {
                if (matrix[i][j] != 0) {
                    temp++;
                }
            }
            if (temp >= maxtemp) {
                maxtemp = temp;
                tempE = vertex[i];
            }
        }
        cout << tempE << " " << maxtemp << endl;
    }
    void printVertex() {
        for (int i = 0; i < numVertex; i++) {
            cout << vertex[i] << ' ';
        }
        cout << endl;
    }
};
#endif

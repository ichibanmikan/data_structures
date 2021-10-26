#ifndef GRAPHREALISE
#define GRAPHREALISE

#include "graphADT.h"
#include <cassert>
#include <iostream>
#include "llink.h"
#include "list.h"
#include "llist.h"

using namespace std;

class Edge{
    private:
        int vert;
        int weight;
    public:
        Edge(){
            vert=-1;
            weight=-1005;
        }
        Edge(int v, int w){
            vert=v;
            weight=w;
        }
        ~Edge() {};
        int getVertex(){
            return vert;
        }
        int getWeight(){
            return weight;
        }
};

ostream& operator << (ostream& s, Edge e){
    return s << '(' << e.getVertex() << ", " << e.getWeight() << ')';
}

template <typename E>
class graphRealise : public graphADT<E>{
    private:
        int numVertex, numEdge;
        LList<Edge>** adjlist;
        // int **matrix;
        int **weight;
        int *mark;
        bool isDirected;
        E *vertex;
    public:
        graphRealise(int n){
            init(n);
        }
        ~graphRealise(){
            delete [] vertex;
            delete [] mark;
            for (int i=numVertex-1; i>=0; i--){
                delete [] weight[i];
                // delete [] adjlist[i];
            }
            delete [] weight;
            // delete [] adjlist;
        }
        // bool operator== (E& g1, E& g2){
        //     if ()
        // }
        void init(int n){
            numVertex=n;
            numEdge=0;
            weight=(int **) new int*[n];
            mark=new int [n];
            vertex=new E [n];
            adjlist=(LList<Edge>**) new LList<Edge> *[n];
            for (int i=0; i<n; i++){
                adjlist[i] = new LList<Edge>();
                mark[i]=0;
                weight[i]=new int[n];
                for (int j=0; j<n; j++){
                    weight[i][j]=0;
                }
            }
        }
        int getnumEdge(){
            return numEdge;
        }
        int getnumVertex(){
            return numVertex;
        }
        int first(int v){
            assert(v<numVertex);
            if (adjlist[v]->length()==0){
                return numVertex;
            }
            adjlist[v]->moveToStart();
            Edge temp=adjlist[v]->getValue();
            return temp.getVertex();
        }
        int next(int v, int w){
            assert(w<numVertex-1&&isEdge(v, w));
            adjlist[v]->next();
            Edge temp=adjlist[v]->getValue();
            return temp.getVertex();
        }
        void setType(int flag){
            if (flag==1){
                isDirected=true;
            }
            else{
                isDirected=false;
            }
        }
        bool getType(){
            return isDirected;
        }
        int locateVex(E u){
            for (int i=0; i<numVertex; i++){
                if (u==vertex[i]){
                    return i;
                }
            }
            return -1;
        }
        E getVex(int v){
            return vertex[v];
        }
        void setVex(int v, E value){
           assert(v<numVertex);
            vertex[v]=value;
        }
        void setEdge(int v1, int v2, int wght){
            assert(v1<numVertex&&v2<numVertex);
            Edge temp(v2, wght);
            if (isEdge(v1, v2)){
                adjlist[v1]->remove();
                adjlist[v1]->insert(temp);
                weight[v1][v2]=wght;
            }
            else{
                numEdge++;
                for (adjlist[v1]->moveToStart(); adjlist[v1]->currPos()<adjlist[v1]->length(); adjlist[v1]->next()){
                    Edge temp2=adjlist[v1]->getValue();
                    if (temp2.getVertex()>v2){
                        break;
                    }
                }
                weight[v1][v2]=wght;
                adjlist[v1]->insert(temp);
                if(!isDirected){
                    Edge temp1(v1, wght);
                    weight[v2][v1]=wght;
                    for (adjlist[v2]->moveToStart(); adjlist[v2]->currPos()<adjlist[v2]->length(); adjlist[v2]->next()){
                        Edge temp2=adjlist[v2]->getValue();
                        if (temp2.getVertex()>v1){
                            break;
                        }
                    }
                    adjlist[v2]->insert(temp1);
                }
            }
        }
        void delEdge(int v1, int v2){
            assert(v1<numVertex&&v2<numVertex);
            if (isEdge(v1, v2)){
                adjlist[v1]->remove();
                numEdge--;
                weight[v1][v2]=0;
                if (!isDirected){
                    adjlist[v2]->remove();
                    numEdge--;
                    weight[v1][v2]=0;
                }
            }
        }
        bool isEdge(int v, int w){
            for (adjlist[v]->moveToStart(); adjlist[v]->currPos() < adjlist[v]->length(); adjlist[v]->next()) {
                Edge temp = adjlist[v]->getValue();
                if (temp.getVertex() == w){
                    return true;
                }
            }
            return false;
        }
        int getWeight(int v, int w){
            assert(isEdge(v, w));
            Edge temp;
            if (isEdge(v, w)) {
                temp=adjlist[v]->getValue();
                return temp.getWeight();
            }
            return 0;
        }
        void setMark(int v, E value){
            mark[v]=value;
        }
        E getMark(int v){
            return mark[v];
        }
        void printweight(){
            for (int i=0; i<numVertex; i++){
                for (int j=0; j<numVertex; j++){
                    cout << weight[i][j] << ' ';
                }
                cout << endl;
            }
        }
        // void printmatrix(){
        //     for (int i=0; i<numVertex; i++){
        //         for (int j=0; j<numVertex; j++){
        //             cout << matrix[i][j] << ' ';
        //         }
        //         cout << endl;
        //     }           
        // }
        void printhelp(){
            for (int i=0; i<numVertex; i++){
                for (adjlist[i]->moveToStart(); adjlist[i]->currPos()<adjlist[i]->length(); adjlist[i]->next()){
                    // if(adjlist[i]->getvalue().vert==)
                    cout << adjlist[i]->getValue() << ' ';
                }
                cout << endl;
            }
        }
        void printVertex(){
            for (int i=0; i<numVertex; i++){
                cout << vertex[i] << ' ';
            }
            cout << endl;
        }
        // int maxoutDegreeNum(){
        //     int maxtemp=0;
        //     for (int i=0; i<numVertex; i++){
        //         int temp=0;
        //         for (int j=0; j<numVertex; j++){
        //             if (matrix[i][j]==1){
        //                 temp++;
        //             }
        //         }
        //         if (temp>=maxtemp){
        //             maxtemp=temp;
        //         }
        //     }
        //     return maxtemp;
        // }
        // E maxoutDegreeVertex(){
        //     E tempE;
        //     int maxtemp=0;
        //     for (int i=0; i<numVertex; i++){
        //         int temp=0;
        //         for (int j=0; j<numVertex; j++){
        //             if (matrix[i][j]==1){
        //                 temp++;
        //             }
        //         }
        //         if (temp>=maxtemp){
        //             maxtemp=temp;
        //             tempE=vertex[i];
        //         }
        //     }
        //     return tempE;
        // }
        // void printMax(){
        //     cout << maxoutDegreeVertex() << ' ' << maxoutDegreeNum() << endl;
        // }
};
#endif
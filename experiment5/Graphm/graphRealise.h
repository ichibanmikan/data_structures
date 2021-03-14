#ifndef GRAPHREALISE
#define GRAPHREALISE

#include "graphADT.h"
#include <cassert>
#include <iostream>

using namespace std;

template <typename E>
class graphRealise : public graphADT<E>{
    private:
        int numVertex, numEdge;
        int **matrix;
        int **weight;
        int *mark;
        bool isDirected;
        E *vertex;
    public:
        graphRealise(int n){
            init(n);
        }
        ~graphRealise(){
            delete [] mark;
            delete [] vertex;
            for (int i=0; i<numVertex; i++){
                delete [] matrix[i];
                delete [] weight[i];
            }
            delete [] matrix;
            delete [] weight;
        }
        // bool operator== (E& g1, E& g2){
        //     if ()
        // }
        void init(int n){
            numVertex=n;
            numEdge=0;
            matrix=(int**) new int *[n];
            weight=(int**) new int *[n];
            for (int i=0; i<n; i++){
                matrix[i]=new int [n];
                weight[i]=new int [n];
            }
            mark=new int [n];
            vertex=new E [n];
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    matrix[i][j]=0;
                    weight[i][j]=-1005;
                }
                mark[i]=0;
            }
        }
        int getnumEdge(){
            return numEdge;
        }
        int getnumVertex(){
            return numVertex;
        }
        int first(int v){
            for (int i=0; i<numVertex; i++){
                if (matrix[v][i]==1){
                    return i;
                }
            }
            return numVertex;
        }
        int next(int v, int w){
            for (int i=w+1; i<numVertex; i++){
                if (matrix[v][i]==1){
                    return i;
                }
            }
            return numVertex;
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
            if (matrix[v1][v2]==0){
                numEdge++;
                matrix[v1][v2]=1;
            }
            weight[v1][v2]=wght;
            if(!isDirected){
                matrix[v2][v1]=1;
                weight[v2][v1]=wght;
            }
        }
        void delEdge(int v1, int v2){
            assert(v1<numVertex&&v2<numVertex);
            if (matrix[v1][v2]==1){
                matrix[v1][v2]=0;
                weight[v1][v2]=-1005;
                if (!isDirected){
                    matrix[v2][v1]=0;
                    weight[v2][v1]=-1005;
                }
            }
        }
        bool isEdge(int v, int w){
            return matrix[v][w]==1;
        }
        int getWeight(int v, int w){
            return weight[v][w];
        }
        void setMark(int v, int value){
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
        void printmatrix(){
            for (int i=0; i<numVertex; i++){
                for (int j=0; j<numVertex; j++){
                    cout << matrix[i][j] << ' ';
                }
                cout << endl;
            }           
        }
        void printhelp(){
            for (int i=0; i<numVertex; i++){
                for (int j=0; j<numVertex; j++){
                    if (matrix[i][j]==1){
                        cout << weight[i][j] << ' ';
                    }
                    else if (matrix[i][j]==0){
                        cout << 0 << ' ';
                    }
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
        int maxoutDegreeNum(){
            int maxtemp=0;
            for (int i=0; i<numVertex; i++){
                int temp=0;
                for (int j=0; j<numVertex; j++){
                    if (matrix[i][j]==1){
                        temp++;
                    }
                }
                if (temp>=maxtemp){
                    maxtemp=temp;
                }
            }
            return maxtemp;
        }
        E maxoutDegreeVertex(){
            E tempE;
            int maxtemp=0;
            for (int i=0; i<numVertex; i++){
                int temp=0;
                for (int j=0; j<numVertex; j++){
                    if (matrix[i][j]==1){
                        temp++;
                    }
                }
                if (temp>=maxtemp){
                    maxtemp=temp;
                    tempE=vertex[i];
                }
            }
            return tempE;
        }
        void printMax(){
            cout << maxoutDegreeVertex() << ' ' << maxoutDegreeNum() << endl;
        }
};
#endif
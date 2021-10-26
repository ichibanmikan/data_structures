#ifndef GRAPH
#define GRAPH

template <typename E> class Graph {
  private:
    void operator=(const Graph &) {} // 重载
    Graph(const Graph &) {}

  public:
    Graph() {}
    virtual ~Graph() {}
    virtual void Init(int n) = 0;
    virtual int getnumVertex() = 0; // 结点数
    virtual int getnumEdge() = 0;   // 边数
    virtual int first(int v) = 0;
    virtual int next(int v, int w) = 0;
    virtual void setType(int flag) = 0; // 设置为有向/无向图
    virtual bool getType() = 0;
    virtual int locateVex(E u) = 0; // 定位结点
    virtual E getVex(int v) = 0;
    virtual void setVex(int v, E value) = 0;
    virtual void setEdge(int v1, int v2, int wght) = 0;
    virtual void delEdge(int v1, int v2) = 0;
    virtual bool isEdge(int v, int w) = 0;
    virtual int getWeight(int v, int w) = 0; // 取权值
    virtual E getMark(int v) = 0;
    virtual void setMark(int v, E value) = 0;
    virtual void printweight() = 0; // 打印权值
    virtual void printVertex() = 0;
    virtual void printMatrix() = 0; // 打印邻接矩阵
    virtual void printMax() = 0; // 打印最大值
};
#endif

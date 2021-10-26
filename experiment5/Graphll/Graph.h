#ifndef GRAPH
#define GRAPH

template <typename E> class Graph {
  private:
    void operator=(const Graph &) {} // ����
    Graph(const Graph &) {}

  public:
    Graph() {}
    virtual ~Graph() {}
    virtual void Init(int n) = 0;
    virtual int getnumVertex() = 0; // �����
    virtual int getnumEdge() = 0;   // ����
    virtual int first(int v) = 0;
    virtual int next(int v, int w) = 0;
    virtual void setType(int flag) = 0; // ����Ϊ����/����ͼ
    virtual bool getType() = 0;
    virtual int locateVex(E u) = 0; // ��λ���
    virtual E getVex(int v) = 0;
    virtual void setVex(int v, E value) = 0;
    virtual void setEdge(int v1, int v2, int wght) = 0;
    virtual void delEdge(int v1, int v2) = 0;
    virtual bool isEdge(int v, int w) = 0;
    virtual int getWeight(int v, int w) = 0; // ȡȨֵ
    virtual E getMark(int v) = 0;
    virtual void setMark(int v, E value) = 0;
    virtual void printweight() = 0; // ��ӡȨֵ
    virtual void printVertex() = 0;
    virtual void printMatrix() = 0; // ��ӡ�ڽӾ���
    virtual void printMax() = 0; // ��ӡ���ֵ
};
#endif

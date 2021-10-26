#ifndef GRAPHADT
#define GRAPHADT

template <typename E>
class graphADT {
private:
    void operator =(const graphADT&) {} 
    graphADT(const graphADT&) {} 
public:
    graphADT() {}
    virtual ~graphADT() {}
    virtual void init(int n) = 0;//初始化
    virtual int getnumVertex() = 0;//返回图结点个数
    virtual int getnumEdge() = 0;//返回图边数
    virtual int first(int v) = 0;//返回第一个相邻节点坐标
    virtual int next(int v, int w) = 0;//返回当前结点下一个相邻结点的坐标
    virtual void setType(int flag) = 0;//设置是有向图还是无向图
    virtual bool getType() = 0; //返回是有向图还是无向图
    virtual int locateVex(E u) = 0;//返回结点位置
    virtual E getVex(int v) = 0; //返回某位置的结点
    virtual void setVex(int v, E value) = 0;//给结点赋值
    virtual void setEdge(int v1, int v2, int wght) = 0;//建立一个边，也就是把权值和坐标赋值
    virtual void delEdge(int v1, int v2) = 0;//删掉某个边
    virtual bool isEdge(int v, int w) = 0;//俩结点之间是边吗
    virtual int getWeight(int v, int w) = 0;//返回权值
    virtual E getMark(int v) = 0;//返回结点本身
    virtual void setMark(int v, int value) = 0;//设置权值。
    virtual E maxoutDegreeVertex() = 0;
    virtual int maxoutDegreeNum() = 0;
    virtual void setComnetwork() = 0;//设置通信网络
    virtual void printweight() = 0;//打印权值矩阵
    virtual void printmatrix() = 0;//打印插入矩阵
    virtual void printhelp() = 0;//打印邻接矩阵
    virtual void printVertex() = 0;//打印结点表
    virtual void printMax() = 0;//打印最大结点与出度值
    virtual void printComnetwork() = 0;//打印通信网络矩阵
    virtual void delComnetWork() = 0; //求解通信网络矩阵
    virtual int allKnow() = 0;//返回有几个都知道的部门
    virtual void resetD() = 0;//重置D
    virtual void Dijkstra(int s)= 0;//Dijkstra算法函数
    virtual int minVertex() = 0;//返回当前距离最小的结点
    virtual int getFinalD() = 0;//返回最终最优路径对应的疲劳程度
    virtual void getAllD() = 0;
};
#endif
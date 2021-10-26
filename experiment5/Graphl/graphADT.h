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
    virtual void setMark(int v, E value) = 0;//设置权值。
    // virtual E maxoutDegreeVertex() = 0;
    // virtual int maxoutDegreeNum() = 0;
    virtual void printweight() = 0;//打印权值矩阵
    // virtual void printmatrix() = 0;//打印插入矩阵
    virtual void printhelp() = 0;//打印邻接矩阵
    virtual void printVertex() = 0;//打印结点表
    // virtual void printMax() = 0;//打印最大结点与出度值
};
#endif


//Node Type
// basic structure of binomial heap node
//insert node into the binomial heap
void trie_insert(trie root, char* key){
    trie_node* node = root;
    char* p = key;
    while(*p){
        if(node->children[*p-'a'] == NULL){
            node->children[*p-'a'] = create_trie_node();
        }
        node = node->children[*p-'a'];
        ++p;
    }
    node->count += 1;
}

/**
 * 查询：不存在返回0，存在返回出现的次数
 */ 
int trie_search(trie root, char* key){
    trie_node* node = root;
    char* p = key;
    while(*p && node!=NULL){
        node = node->children[*p-'a'];
        ++p;
    }
    if(node == NULL)
        return 0;
    else
        return node->count;
}

/*
tree[k]'s left child is tree[2*k], 
right child is tree[2*k+1];
*/


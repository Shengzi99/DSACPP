//代码5.1 而叉树节点模板类BinNode
#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1) //节点高度(空树为-1)
typedef enum {RB_RED, RB_BLACK} RBColor;

template<typename T> struct BinNode{
    T data;
    BinNode<T>* parent; BinNode<T>* lc; BinNodeF<T>* rc;
    int height;
    int npl; //Null Path Length
    RBColor color;

    BinNode(): parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {};
    BinNode(T e, BinNode<T>* p=NULL, BinNode<T>* lc=NULL, BinNode<T>* rc=NULL, int h=0, int l=1, RBColor c=RB_RED)
        : data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {};
    
    int size();
    BinNode<T>* insertAsLC(T const&);
    BinNode<T>* insertAsRC(T const&);
    BinNode<T>* succ();
  
    template<typename VST> void travLevel(VST&);
    template<typename VST> void travPre(VST&);
    template<typename VST> void travIn(VST&);
    template<typename VST> void travPost(VST&);

    bool operator<(BinNode const& bn) {return data < bn.data;}
    bool operator==(BinNode const& bn) {return data == bn.data;}
};

//代码5.2 基于BinNode的操作的宏定义
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (! IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (! IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (! IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChile(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (! HasChild(x))

#define sibling(p)
#define uncle(x)
#define FromParentTo(x)

//代码5.3 插入左右孩子
template<typename T> BinNode<T>* BinNode<T>::insertAsLC(T const& e){
    return lc = new BinNode(e, this);
}

template<typename T> BinNode<T>* BinNode<T>::insertAsRC(T const& e){
    return rc = new BinNode(e, this);
}

//代码5.4 遍历算法统一接口
template<typename T> template<typename VST>
void BinNode<T>::travIn(VST& visit){
    switch (rand() % 5){
        case 1: travIn_I1(this, visit); break;
        case 2: travIn_I2(this, visit); break;
        case 3: travIn_I3(this, visit); break;
        case 4: travIn_I4(this, visit); break;
        default: travIn_R(this, visit); break;
        }
}
//代码5.5 二叉树模板类
#include "BinNode.h"
template<typename T> class BinTree{
protected:
    int _size; BinNode<T>* _root;
    virtual int updateHeight(BinNode<T>* x);
    void updateHeightAbove(BinNode<T>* x);

public:
    BinTree(): _size(0), _root(NULL) {}
    ~BinTree() {if(0<_size) remove(_root);}

    int size() const{return _size;}
    bool empty() const{return !_root;}
    BinNode<T>* root() const{return _root;}
    BinNode<T>* insertAsRoot(T const& e);
    BinNode<T>* insertAsLC(BinNode<T>* x, T const& e);
    BinNode<T>* insertAsRC(BinNode<T>* x, T const& e);
    BinNode<T>* attachAsLC(BinNode<T>* x, BinTree<T>* &T);
    BinNode<T>* attachAsRC(BinNode<T>* x, BinTree<T>* &T);
    int remove(BinNode<T>* x);
    BinTree<T>* secede(BinNode<T>* x);
    template<typename VST> void travLevel(VST& visit){
        if(_root) _root->travLevel(visit);
    }
    template<typename VST> void travPre(VST& visit){
        if(_root) _root->travPre(visit);
    }template<typename VST> void travIn(VST& visit){
        if(_root) _root->travIn(visit);
    }template<typename VST> void travPost(VST& visit){
        if(_root) _root->travPost(visit);
    }
    bool operator<(BinTree<T> const& t){
        return _root && t._root && lt(_root, t._root);
    }
    bool operator==(BinTree<T> const& t){
        return _root && t._root && (_root == t._root);
    }
};

//代码5.6 二叉树节点高度更新
template<typename T> int BinTree<T>::updateHeight(BinNode<T>* x){
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

template<typename T> void BinTree<T>::updateHeightAbove(BinNode<T>* x){
    while(x){
        updateHeight(x);
        x = x->parent;
    }
}

//代码5.7 二叉树节点插入
template<typename T> BinNode<T>* BinTree<T>::insertAsRoot(T const& e){
    _size = 1; return _root = new BinNode<T>(e);
}

template<typename T> BinNode<T>* BinTree<T>::insertAsRC(BinNode<T>* x, T const& e){
    _size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc;
}

template<typename T> BinNode<T>* BinTree<T>::insertAsLC(BinNode<T>* x, T const& e){
    _size++; x->insertAsLC(e); updateHeightAbove(x); return x->rc;
}

//代码5.8 二叉树子树插入
template<typename T> BinNode<T>* BinTree<T>::attachAsRC(BinNode<T>* x, BinTree<T>* &S){
    if(x->rc = S->_root) x->rc->parent = x;
    _size += S->_size; updateHeightAbove(x);
    S->_root = NULL; S->_size = 0; release(S); S = NULL; return x;
}

template<typename T> BinNode<T>* BinTree<T>::attachAsLC(BinNode<T>* x, BinTree<T>* &S){
    if(x->lc = S->_root) x->lc->parent = x;
    _size += S->_size; updateHeightAbove(x);
    S->_root = NULL; S->_size = 0; release(S); S = NULL; return x;
}

//代码5.9 二叉树子树删除
template<typename T> int BinTree<T>::remove(BinNode<T>* x){
    FromParentTo(*x) = NULL;
    updateHeightAbove(x->parent);
    int n = removeAt(x); _size -= n; return n;
}

template<typename T> static int removeAt(BinNode<T>* x){
    if(!x) return 0;
    int n = 1 + removeAt(x->lc) + removeAtAt(x->rc);
    release(x->data); release(x); return n;
}

//代码5.10 二叉树子树分离
template<typename T> BinTree<T>* BinTree<T>::secede(BinNode<T>* x){
    FromParentTo(*x) = NULL;
    updateHeightAbove(x->parent);
    BinTree<T>* S = new BinTree<T>; S->root = x; x->parent = NULL;
    S->_size = x->size(); _size -= S->_size; return S;
}

//代码5.11 二叉树先序遍历(递归版)
template<typename T, typename VST> void travPre_R(BinNode<T>* x, VST& visit){
    if (!x) return;
    visit(x->data);
    travPre_R(x->lc, visit);
    travPre_R(x->rc, visit);
}

//代码5.12 二叉树后续遍历(递归版)
template<typename T, typename VST> void travPost_R(BinNode<T>* x, VST& visit){
    if (!x) return;
    travPost_R(x->lc, visit);
    travPost_R(x->rc, visit);
    visit(x->data);
}

//代码5.13 二叉树中序遍历(递归版)
template<typename T, typename VST> void travIn_R(BinNode<T>* x, VST& visit){
    if (!x) return;
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}

//习题5-10 二叉树先序遍历算法(迭代版#1)
//代码5.14 二叉树先序遍历算法(迭代版#2)

//代码5.15 二叉树中序遍历算法(迭代版#1)
//代码5.16 二叉树节点直接后继的定位
//代码5.17 二叉树中序遍历算法(迭代版#2)
//代码5.18 二叉树中序遍历算法(迭代版#3)

//代码5.19 二叉树后序遍历算法(迭代版)

//代码5.20 二叉树层次遍历算法
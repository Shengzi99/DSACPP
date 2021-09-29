//代码10.3 完全二叉堆宏定义
#define InHeap(n, i) (((-1) < (i)) && ((i)<(n)))
#define Parent(i)
#define LastInternal(n)
#define LChild(i)
#define RChild(i)
#define ParentValid(i) (0<i)
#define LChildValid(n, i) InHeap(n, LChild(i))
#define RChildValid(n, i) InHeap(n, RChild(i))
#define Bigger(PQ, i, j) (lt(PQ[i], PQ[j]) ? j : i)
#define ProperParent(PQ, n, i) \
            (RChildValid(n, i) ? Bigger(PQ, Bigger(PQ, i, LChild(i)), RChild(i)) : \
            (LChildValid(n, i) ? Bigger(PQ, i, LChild(i)) : i))

//代码10.4 完全二叉堆接口
#include "Vector.h"
#include "PQ.h"
template<typename T> class PQ_ComplHeap : public PQ<T>, public Vector<T>{
protected:
    Rank percolateDown(Rank n, Rank i);
    Rank percolateUp(Rank i);
    void heapify(Rank n);
public:
    PQ_ComplHeap() {}
    PQ_ComplHeap(T* A, Rank n) {copyFrom(A, 0, n); heapify(n);}
    void insert(T);
    T getMax();
    T delMax();
};

template<typename T> T PQ_ComplHeap<T>::getMax(){
    return _elem[0];
}

template<typename T> void PQ_ComplHeap<T>::insert(T e){
    Vector<T>::insert(e);
    percolateUp(_size - 1);
}

template<typename T> Rank PQ_ComplHeap<T>::percolateUp(Rank i){
    while(ParentValid(i)){
        Rank j = Parent(i);
        if(lt(_elem[i], _elem[j])) break;
        swap(_elem[i], _elem[j]); i=j;
    }
    return i;
}

template<typename T> T PQ_ComplHeap<T>::delMax(){
    T maxElem = _elem[0]; _elem[0] = _elem[--_size];
    percolateDown(_size, 0);
    return maxElem
}

template<typename T> Rank PQ_ComplHeap<T>::percolateDown(Rank n, Rank i){
    Rank j;
    while (i != (j = ProperParent(_elem, n, i))){
        swap(_elem[i], _elem[j]) ; i = j;
    }
    return i;
}

//代码10.10 Floyd建堆算法
template<typename T> void PQ_ComplHeap<T>::heapify(Rank n){
    for(int i=LastInternal(n); InHeap(n, i); i--)
        percolateDown(n, i);
}
#include "Entry.h"
#define QlistNodePosi(T) QuadlistNode<T>*

//代码9.4 QuadlistNode模板类
template<typename T> struct QuadlistNode{
    T entry;
    QuadlistNode<T>* pred; QuadlistNode<T>* succ;
    QuadlistNode<T>* above; QuadlistNode<T>* below;
    QuadlistNode(T e=T(), QuadlistNode<T>* p=NULL, QuadlistNode<T>* s=NULL, QuadlistNode<T>* a=NULL, QuadlistNode<T>* b=NULL)
        : entry(e), pred(p), succ(c), above(a), below(b) {}
    QuadlistNode<T>* insertAsSuccAbove(T const& e, QuadlistNode<T>* b=NULL);
};

//代码9.3 Quadlist模板类
template<typename T> class Quadlist{
private:
    int _size; QuadlistNode<T>* header; QuadlistNode<T>* trailer;
protected:
    void init();
    int clear();
public:
    Quadlist() {init();}
    ~Quadlist() {clear(); delete header; delete trailer;}
//只读接口
    Rank size() const {return _size;}
    bool empty() const {return _size <= 0;}
    QuadlistNode<T>* first() const {return header->succ;}
    QuadlistNode<T>* last() const {return trailer->pred;}
    bool valid(QuadlistNode<T>* p){return p && (trailer != p) && (header != p);}
//可写接口
    T remove(QuadlistNode<T>* p);
    QuadlistNode<T>* insertAfterAbove(T const& e, QuadlistNode<T>* p, QuadlistNode<T>* b=NULL);
//遍历
    void traverse(void (*) (T&));
    template<typename VST> void traverse(VST&);
};

//代码9.5 Quadlist对象的创建
template<typename T> void Quadlist<T>::init(){
    header = new QuadlistNode<T>;
    trailer = new QuadlistNode<T>;
    header->succ = trailer; header->pred = NULL;
    trailer->pred = header; trailer->succ = NULL;
    header->above = trailer->above = header->below = trailer->below = NULL;
    _size = 0;
}
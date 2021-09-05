typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template<typename T> struct ListNode{
    T data; ListNode<T>* pred; ListNode<T>* succ;

    ListNode() {}
    ListNode(T e, ListNode<T>* p = NULL, ListNode<T>* s = NULL) : data(e), pred(p), succ(s) {}

    ListNode<T>* insertAsPred(T const& e);
    ListNode<T>* insertAsSucc(T const& e);
};

template<typename T> class List{

private:
    int _size; ListNode<T>* header; ListNode<T>* trailer;

protected:
    void init();
    int clear();
    void copyNodes(ListNode<T>*, int);
    void merge(ListNode<T>*&, int, List<T>&, ListNode<T>*, int);
    void mergeSort(ListNode<T>*&, int);
    void selectionSort(ListNode<T>*, int);
    void insertionSort(ListNode<T>*, int);

public:
    List() {init(); }
    List(List<T> const& L);
    
};

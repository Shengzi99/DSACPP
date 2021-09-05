//代码2.1 向量模板类Vector
typedef int Rank; //秩
#define DEFAULT_CAPACITY 3 //默认的初始容量

template <typename T>
class Vector{
protected:
    Rank _size; int _capacity; T* _elem;
    void copyFrom(T const* A, Rank lo, Rank hi); //复制数组区间

    void expand(); //扩容
    void shrink(); //压缩

// 排序算法
    bool bubble(Rank lo, Rank hi); //交换
    void bubbleSort(Rank lo, Rank hi); //起泡排序

    Rank max(Rank lo, Rank hi); //选取最大元素
    void selectionSort(Rand lo, Rank hi); //选择排序

    void merge(Rank lo, Rank mi, Rank hi); //归并算法
    void mergeSort(Rank lo, Rank hi); //归并排序

    Rank partition(Rank lo, Rank hi); //轴点构造算法
    void quickSort(Rank lo, Rank hi); //快速排序

public:
// 构造函数
    Vector(int c=DEFAULT_CAPACITY, int s=0, T v=0)
    {
        _elem = new T[_capacity=c];
        for(_size=0; _size<s; _elem[_size = ++v);
    }
    Vector(T const* A, Rank n){copyFrom(A, 0, n);} //数组整体复制
    Vector(T const* A, Rank lo, Rank hi){copyFrom(A, lo, hi);} //数组区间复制
    Vector(Vector<T> const& V){copyFrom(V._elem, 0, V._size);} //向量整体复制
    Vector(Vector<T> const& V, Rank lo, Rank hi){copyFrom(V._elem, lo, hi);} //向量区间复制

// 析构函数
    ~Vector() {delete [] _elem; /*释放内存*/ }
// 只读访问接口
    Rank size() const{return _size; } //规模
    bool empty() const{return !_size; } //判空
    int disordered() const; //判序
    Rank find(T const& e) const;
    Rank find(T const& e, Rank lo, Rank hi) const;
    Rank search(T const& e) const;
    Rank search(T const& e, Rank lo, Rank hi) const;

// 可写访问接口
    T& operator[] (Rank r) const;
    Vector<T> & operator= (Vector<T> const&);
    T remove(Rank r);
    int remove(Rank io, Rank hi);
    Rank insert(Rank r, T const& e);
    Rank insert(T const& e);
    void sort(Rank lo, Rank hi);
    void sort();
    void unsort(Rank lo, Rank hi);
    void unsort();
    int deduplicate(); //无序去重
    int unipuify(); //有序去重
// 遍历
    void traverse(void (*) (T&));
    template<typename VST> void traverse(VST&);
};

//代码2.2 基于复制的向量构造器
template<typename T> void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi){
    _elem = new T[_capacity = 2 * (hi - lo)]; _size = 0;
    while(lo < hi)
        _elem[_size++] = A[lo++];
}

//代码2.3 重载向量赋值操作符
template<typename T> Vector<T>& Vector<T>::operator=(Vector<T> const& V){
    if (_elem) delete[] _elem;
    copyFrom(v._elem, 0, V.size());
    return *this; //返回当前对象的引用,以便链式赋值
}

//代码2.4 向量内部数组动态扩容算法expand()
template<typename T> void Vector<T>::expand(){
    if(_size < _capacity) return;
    if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T* oldElem = _elem; _elem = new T[_capacity <<= 1];
    for(int i=0; i < _size; i++)
        _elem[i] = oldElem[i];
    delete[] oldElem;
}

//代码2.5 向量内部功能shrink()
template<typename T> void Vector<T>::shrink(){
    if(_capacity < DEFAULT_CAPACITY << 1) return;
    if(_size << 2 > _capacity) return; //以25%为界
    T* oldElem = _elem; _elem = new T[_capacity >>=1];
    for(int i=0; i<_size; i++) _elem[i] = oldElem[i];
    delete[] oldElem;
}

//代码2.6 重载向量操作符[]
template<typename T> T& Vector<T>::operator[](Rank r) const{
    return _elem[r];
}

//代码2.7 向量整体置乱算法permute()
// template<typename T> void permute(Vector<T>& v){
//     for(int i=V.size(); i>0; i--)
//         swap(V[i - 1], V[rand() % i]);
// }

//代码2.8 向量体区间置乱接口unsort()
template<typename T> void Vector<T>::unsort(Rank lo, Rank hi){
    T* V = _elem + lo; //将子向量_elem[lo, hi)视作另一向量
    for(Rank i = hi - lo; i > 0; i--)
        swap(V[i - 1], V[rand() % i]);
}

//代码2.9 重载比较器以便比较对象指针

//代码2.10 无序向量元素查找
template<typename T> Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const{
    while((lo < hi--) && (e != _elem[hi]));
    return hi;
}

//代码2.11 向量元素插入接口insert()
template<typename T> Rank Vector<T>::insert(Rank r, T const& e){
    expand();
    for(int t=_size; i > r; i--) _elem[i] = _elem[i-1];
    _elem[r] = e; _size++;
    return r;
}

//2.12
template<typename T> int Vector<T>::remove(Rank lo, Rank hi){
    if(lo == hi) return 0;
    while(hi < _size) _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi - lo;
}

//2.13
template<typename T> T Vector<T>::remove(Rank r){
    T e = _elem[r];
    remove(r, r+1);
    return e;
}

//2.14
template<typename T> int Vector<T>::deduplicate(){
    int oldSize = _size;
    Rank i = 1;
    while (i < _size)
        (find(_elem[i], 0, i) < 0) ? i++ : remove(i);
    return oldSize - _size;
}

//2.15
template<typename T> void Vector<T>::traverse(void (*visit) (T&)){
    for(int i=0; i<_size; i++) visit(_elem[i]);
}

template<typename T> template<typename VST>
void Vector<T>::traverse(VST& visit){
    for(int i=0; i<_size; i++) visit(_elem[i]);
}

//2.16
template<typename T> struct Increase
{
    virtual void operator() (T& e){
        e++;
    }
};

template<typename T> void increase(Vector<T> & V){
    V.traverse(Increase<T>());
}

//2.17
template<typename T> int Vector<T>::disordered() const{
    int n = 0;
    for(int i=1; i<_size; i++)
        if(_elem[i-1] > _elem[i]) n++;
    return n;
}

//2.18
template<typename T> int Vector<T>::unipuify(){
    int oldSize = _size; int i = 1;
    while(i < _size)
        _elem[i - 1] == _elem[i] ? remove(i) : i++;
    return oldSize - _size;
}

//2.19 
template<typename T> int Vector<T>::unipuify(){
    Rank i = 0, j = 0;
    while(++j < _size)
        if(_elem[i] != _elem[j]) _elem[++i] = _elem[j];
    _size = ++i; shrink();
    return j - i;
}

//2.20
template<typename T> Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const{
    return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}

//代码2.21 二分查找(版本A)
template<typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi){
    while (lo < hi){
        Rank mi = (lo + hi) >> 1;
        if (e < A[mi]) hi = mi;
        else if (A[mi] < e) lo = mi + 1;
        else return mi;
    }
    return -1;
}

//代码2.22 Fib查找
template<typename T> static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi){
    Fib fib(hi - lo);
    while (lo < hi){
        while (hi - lo < fib.get()) fib.prev();
        Rank mi = lo + fib.get() - 1;
        if (e < A[mi]) hi = mi;
        else if (A[mi] < e) lo = mi + 1;
        else return mi;
    }
    return -1;
}

//代码2.23 二分查找(版本B)
template<typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi){
    while (1 < hi - lo){
        Rank mi = (lo + hi) >> 1;
        (e < A[mi]) ? hi = mi : lo = mi;
    }
    return (e == A[lo]) ? lo : -1;
}

//代码2.24 二分查找(版本C)
template<typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi){
    while (lo < hi){
        Rank mi = (lo + hi) >> 1;
        (e < A[mi]) ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

//代码2.25 向量排序器接口
template<typename T> void Vector<T>::sort(Rank lo, Rank hi){
    switch (rand() % 5){
        case 1: bubbleSort(lo, hi); break;
        case 2: selectionSort(lo, hi); break;
        case 3: mergeSort(lo, hi); break;
        case 4: heapSort(lo, hi); break;
        default: quickSort(lo, hi); break;
    }
}

//代码2.26 起泡排序

//代码2.27 单趟扫描交换

//代码2.28 向量的归并排序

//代码2.29 有序向量的二路归并
#include "Vector.h"

//代码4.1 Stack模板类
template<typename T> class Stack: public Vector<T>{
public:
    void push(T const& e) {insert(size(), e);}
    T pop() {return remove(size() - 1);}
    T& top() {return (*this) [size() - 1];}
};

//代码4.2 进制转换(递归版)

//代码4.3 进制转换(迭代版)

//代码4.4 括号匹配算法(递归版)

//代码4.5 括号匹配算法(迭代版)


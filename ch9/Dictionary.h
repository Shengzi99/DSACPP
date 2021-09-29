//代码9.1 词典结构队操作接口规范
template<typename K, typename V> struct Dictionary{
    virtual int size() const =0;
    virtual bool put(K, V) =0;
    virtual V* get(K k) =0;
    virtual bool remove(K k) =0;
};

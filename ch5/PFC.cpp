//代码5.22 实现PFC编码所需的数据结构
#include "BinTree.h"
typedef BinTree<char> PFCTree;

#include "Vector.h"
typedef Vector<PFCTree*> PFCForest;

#include "Bitmap.h"
#include "Skiplist.h"
typedef Skiplist<char, char*> PFCTable;

#define N_CHAR (0x80 - 0x20)

//代码5.23 初始化PFC森林
PFCForest* initForest(){
    PFCForest* forest = new PFCForest;
    for(int i=0; i<N_CHAR; i++){
        forest->insert(i, new PFCTree());
        (*forest)[i]->insertAsRoot(0x20 + i);
    }
    return forest;
}

//代码5.24 构造PFC编码树
PFCTree* generateTree(PFCForest* forest);

//代码5.25 生成PFC编码表
void generateCT(Bitmap* code, int length, PFCTable* table, BinNode<char>* v){

}//通过遍历获取各字符的编码

PFCTable* generateTable(PFCTree* tree){

}//构造PFC编码表

//代码5.26 PFC编码
int encode(PFCTable* table, Bitmap& codeString, char* s){

}

//代码5.27 PFC编码
void decode(PFCTree* tree, Bitmap& code, int n){
    
}

//代码5.21 基于二叉树队PFC编码
int main(int argc, char* argv[]){
    PFCForest* forest = initForest();
    PFCTree* tree = generateTree(forest); release(forest);
    PFCTable* table = generateTable(tree);
    for(int i = 1; i < argc; i++){
        Bitmap codeString;
        int n = encode(table, codeString, argv[i]);
        decode(tree, codeString, n);
    }
    release(table); release(tree); return 0;
}
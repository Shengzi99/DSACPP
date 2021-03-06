//代码5.28 基于Huffman树的二叉树编码
int main(int argc, char* argv[]){
    int* freq = statistics(argv[1]);
    HuffForest* forest = initForest(freq); release(freq);
    HuffTree* tree = generateTree(forest); release(forest);
    HuffTable* table = generateTable(tree);
    for(int i=2; i<argc; i++){
        Bitmap* codeString = new Bitmap;
        int n = encode(table, codeString, argv[i]);
        decode(tree, codeString, n);
        release(codeString);
    }
    release(table); release(tree); return 0;
}
#include "BST.h"

nodeType *T;

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};

    T = creatnewNode(a[0]);
    treetype tree  = T;
    add_left(&tree, a[1]);
    add_right(&tree, a[2]);
    add_left(&tree->left,a[3]);
    add_right(&tree->left,a[4]);
    add_left(&tree->right,a[5]);
    add_right(&tree->right,a[6]);
    add_left(&tree->left->right,a[7]);
    add_right(&tree->right->left,a[8]);

    printf("Cay co %d la.\n", countLeaves(T));
    printf("Cay co chieu cao %d.\n", height(tree));
    printf("Cay co %d nut trong.\n", countInterNode(tree) - 1);// trừ đi nút gốc của cây
    printf("Cay co %d nut con phai.\n", countRightChild(tree));
    
    return 0;
}

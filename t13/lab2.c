#include "BST.h"
#include<math.h>

nodeType *t;

int main(){
    int a[] = {15,2,8,12,30,21,4,25,43};
    
    t = creatnewNode(a[0]);
    treetype T = t;
    InsertNode(&T, a[1]);
    InsertNode(&T, a[2]);
    InsertNode(&T, a[3]);
    InsertNode(&T, a[4]);
    InsertNode(&T, a[5]);
    InsertNode(&T, a[6]);
    InsertNode(&T, a[7]);
    InsertNode(&T, a[8]);

    printf("Cay co %d la.\n", countLeaves(T));
    printf("Cay co chieu cao %d.\n", height(T));
    printf("Cay co %d nut trong.\n", countInterNode(T) - 1);// trừ đi nút gốc của cây
    printf("Cay co %d nut con phai.\n", countRightChild(T));
    printf("\n");
    printf("duyet thu tu truoc:  ");NLR(T);printf("\n");
    printf("duyet thu tu giua:   ");LNR(T);printf("\n");
    printf("duyet thu tu sau:    ");LRN(T);printf("\n");
    DeleteNode(&T, 12);
    DeleteNode(&T, 30);
    printf("duyet thu tu truoc:  ");NLR(T);printf("\n");
    printf("duyet thu tu giua:   ");LNR(T);printf("\n");
    printf("duyet thu tu sau:    ");LRN(T);printf("\n");
    return 0;
}
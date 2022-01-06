#include "BST.h"
#include<stdio.h>
int main(){
    bst t=NULL;
    int a[9]={1,3,15,6,-9,54,49,32,26};
    for(int i=0; i<9;i++){
        InsertNode(t,a[i]);
    }
    bst x = Search(t, 15);
    printf("Find: %d", x->data);
    bst y = Search(t, 2);
    printf("Find: %d", y->data);
    return 0;
}
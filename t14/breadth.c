#include<stdio.h>
#include "queue.h"
#include "bintree.h"
void breadth(bintree T){
    queue queue;
    if (T!=NULL){
        enqueue(T, queue);
        while(!isempty(queue)){
            T=dequeue(queue);
            printf("%d",T->data);
            if (T->left !=NULL) enqueue(T->left, queue);
            if (T->right !=NULL) enqueue(T->right, queue);
        }
    }
}
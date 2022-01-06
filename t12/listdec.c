#include<stdio.h>
#include<math.h>
#include "quicksort.h"
#define MAX 1000
typedef struct {
    int key;
} element;

/*element list[MAX];
void verify1(element list1[], element list2[], int n, int m){
    int i,j;
    int marked[MAX];
    for (i=0;i<m;i++) marked[i]= -1;
    for (i=0;i<m;i++){
        if ((j=seqsearch(list2,m,list1[i].key))<0)
            printf("%d is not in list 2\n", list1[i].key);
        else marked[j] = 1;
    for (i=0;i<m;i++) 
        if (!marked[i]) printf("%d is not in list 1\n", list2[i].key);
    }
}*/

void verify2(int list1[], int list2[], int n, int m){
    int i=0,j=0;
    quickSort(list1,0,n);
    quickSort(list2,0,m);
    while (i<n && j<m){
        if (list[i].key<list2[i].key){
            printf(" %d is not in list 2\n", list1[i].key);
            i++;
        } else if (list1[i].key == list2[i].key){
            i++;
            j++;
        } else {
            printf("%d is not int list 1\n", list2[i].key);
            j++;
        }
    for (;j<m;j++) printf("%d is not in list 1\n", list2[i].key);
    for (;i<n;i++) printf("%d is not in list 2\n", list1[i].key);
    }
}
int main(){
    int list1[9]={1,2,3,4,5,6,7,8,9};
    int list2[9]={6,7,8,9,10,11,12,13,14};
    verify2(list1,list2,8,8);
    return 0;
}
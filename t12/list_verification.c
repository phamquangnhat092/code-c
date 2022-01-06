#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1000
#define TRUE 1;
#define FALSE 0;

typedef struct{
    int key;
}element;

element list[MAX_SIZE];

int compare(int a, int b){
    if(a > b) return 1;
    else if ( a < b) return -1;
    else return 0;
}

int binsearch(element list[],int n, int searchNum){
    int left = 0, right = n -1 , middle;
    while(left <= right){
        middle = (left + right)/2;
        switch(compare(list[middle].key, searchNum)){
            case -1: 
                left = middle +1;
                break;
            case 0:
                return middle;
            case 1:
                right = middle -1;
        }
        
    }
    return -1;
}

void verify1(element list1[], element list2[], int n, int m){
    int i, j;
    int marked[MAX_SIZE];

    for(int i = 0; i < m; i++){
        marked[i] = FALSE;
    }

    for(i = 0; i < n; i++){
        if((j = binsearch(list2, m, list1[i].key)) < 0){
            printf("%d is not in list2\n", list1[i].key);
        }
        else{
            marked[j] = TRUE;
        }
    }
    printf("\n");
    
    for(i = 0; i< m; i++){
        if(!marked[i]){
            printf("%d is not in list1\n", list2[i].key);
        }
    } printf("\n");
    for(i = 0; i< m; i++){
        if(marked[i]){
            printf("%d is in 2 list\n", list2[i].key);
        }
    }

}

int main(){
    element list1[9]={1,2,3,4,5,6,7,8,9};
    element list2[9]={6,7,8,9,10,11,12,13,14};
    for (int a=0;a<(sizeof(list1)/sizeof(list1[0]));a++) 
    printf("%-3d",list1[a]);printf("\n");
    for (int b=0;b<(sizeof(list2)/sizeof(list2[0]));b++) 
    printf("%-3d",list2[b]);printf("\n");
    verify1(list1, list2, 9, 9);
    return 0;

}
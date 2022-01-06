#include<stdio.h>
#define MAX 50
typedef struct eletype{
    int key;
}eletype;
int m;
eletype a[MAX];
void insertion_sort(eletype list[], int n){
    int i,j;
    eletype next;
    for(i=1; i<n;i++){
        next=list[i];
        for(j=i-1; j>0 && next.key<list[j].key; j--)
            list[j+1] = list[j];
        list[j+1] = next;
        
        for (int x=0; x<n; x++){
            printf(" a[%d] = %d ", x, list[x].key);
        } 
        printf("\n");
    }
}
void insertion_sort1(){
    insertion_sort(a,m);
}

void selection_sort(eletype list[], int n){
    int i,j,min,tmp;
    for ( i=0; i<n-1; i++){
        min = i;
        for (j= i+1; j<= n-1; j++){
            if (list[j].key < list[min].key)
                min=j;
        }
        tmp = list[i].key;
        list[i] = list[min];
        list[min].key = tmp;    
        for (int x=0; x<n; x++){
            printf(" a[%d] = %d ", x, list[x].key);
        } 
        printf("\n");          
    }
}
void selection_sort1(){
    selection_sort(a,m);
}

void bubble_sort(eletype list[], int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int tmp;
            if (list[i].key > list[j].key){
                tmp = list[i].key;
                list[i] = list[j];
                list[j].key = tmp;
            }
        }
        for (int x=0; x<n; x++){
            printf(" a[%d] = %d ", x, list[x].key);
        } 
        printf("\n");
    }
}
void bubble_sort1(){
    bubble_sort(a,m);
}

void adjust(eletype list[],int r, int n){
    int child, rkey;
    eletype tmp = list[r];
    rkey = list[r].key;
    child = 2*r;
    while (child<=n){
        if ((child<n) && (list[child].key < list[child+1].key)) child++;
        if (rkey>list[child].key) break;
        else {
            list[child/2] = list[child];
            child *= 2;
        }
    }
    list[child] = tmp;
}
void heap_sort(eletype list[], int n){
    int i, j;
    int tmp;
    for (i=n/2; i>0; i--) adjust(list, i, n);
    for (i=n-1; i>0; i--){
        tmp = list[1].key;
        list[1] = list[i+1];
        list[i+1].key = tmp; 
        adjust(list, 1, i);
    }  
    for (int x=0; x<n; x++){
            printf(" a[%d] = %d ", x, list[x].key);
        } 
        printf("\n");  
}
void heap_sort1(){
    heap_sort(a,m);
}

void menu(){
    printf("\n        Menu\n");
    printf("1.Insertion Sort\n");
    printf("2.Selection Sort\n");
    printf("3.Bubble Sort\n");
    printf("4.Heap Sort\n");
    printf("5.Quit\n");
    printf("Choose:");
    int x;
    scanf("%d", &x);
    switch(x){
        case 1:
            insertion_sort1();
            menu();
            break;
        case 2:
            selection_sort1();
            menu();
            break;
        case 3:
            bubble_sort1();
            menu();
            break;
        case 4:
            heap_sort1();
            menu();
            break;
        default:
            break;
    }
}
int main(){
    
    printf("Nhap so phan tu m: "); scanf("%d", &m);
    
    for(int k=1; k<=m; k++){
        printf("Nhap phan tu thu %d: ", k+1);
        scanf("%d", &a[k]);
    }
    menu();
    // insertion_sort(a,m);
    printf("\n");
    return 0; 
    //selection_sort(a,m);
    //bubble_sort(a,m);
}
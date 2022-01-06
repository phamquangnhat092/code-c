#include <stdio.h>
#include <time.h>
#include <string.h>
#define MAX 500000

void menu();
// Sequential Search
int LinearSearch(int list[], int n, int searchingNum);
// Sentinel search
int LinearSentinelSearch(int list[], int n, int searchingNum);
// Bin search
int binarySearch(int list[],int n, int searchingNum);

int arr[MAX];
void menu(){
    printf("\nMenu.\n");
    printf("1. Sequential search.\n");
    printf("2. Sequential search using sentinel.\n");
    printf("3. Binary search.\n");
    printf("4. Exit.\n");
    printf("Your selection: ");
    int x; scanf("%d", &x);
    int i = -1;
    switch (x){
        case 1: 
            printf("\nEnter the number: ");
            int searchingNum;
            scanf("%d", &searchingNum);
            i = LinearSearch(arr, MAX, searchingNum);
            if(i != -1){
                printf("Number position: %d\n", i);
            }
            else{
                printf("Not found!\n");
            }
            menu();
            break;
        case 2:
            printf("\nEnter the number: ");
            int searchingNum1;
            scanf("%d", &searchingNum1);
            i = LinearSentinelSearch(arr, MAX, searchingNum1);
            if(i == MAX){
                printf("Number havenot been found!\n");
            }
            else{
                printf("Number position: %d\n", i);
            }
            menu();
            break;
        case 3:
            printf("\nEnter the number: ");
            int searchingNum2;
            scanf("%d", &searchingNum2);
            i = binarySearch(arr, MAX, searchingNum2);
            if(i != -1){
                printf("Number position: %d\n", i);
            }
            else{
                printf("Number havenot been found!!\n");
            }
            menu();
            break;
        default :
            break;
    }
    
}

int cmp(int a, int b){
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}

int binarySearch(int list[],int n, int searchingNum){
    clock_t begin, end;
    double time_used;
    begin = clock();
    int l = 0, r = n -1 , m;
    while(l <= r){
        m = (l + r)/2;
        switch(cmp(list[m], searchingNum)){
            case -1: 
                l = m +1;
                break;
            case 0:
            end = clock();
            time_used = ((double) (end - begin)) / CLOCKS_PER_SEC;
            printf("Running time: %.9f\n", time_used);
                return m;
            case 1:
                r = m -1;
        }
        
    }
    end = clock();
    time_used = ((double) (end - begin)) / CLOCKS_PER_SEC;
    printf("Running time: %.9f\n", time_used);
    return -1;
}

// Sequential Search
int LinearSearch (int list[], int n, int searchingNum) {
    int k = 0;
    clock_t begin, end, time_used;
    begin = clock();
    while (list[k] != searchingNum && k < n)
        k++;
    if (k < n){
        end = clock();
        time_used = ((double) (end - begin)) / CLOCKS_PER_SEC;
        printf("Running time: %.9f\n", time_used);
        return k;
    }
    else {
        return -1;
    }
}

// Sentinel search
int LinearSentinelSearch (int list[], int n, int searchingNum) {
    int k= 0;
    clock_t begin, end;
    double time_used;
    begin = clock();
    list[n]=searchingNum;
    while (list[k] != searchingNum)
        k++;
    end = clock();
    time_used = ((double) (end - begin)) / CLOCKS_PER_SEC;
    printf("Running time: %.9f\n", time_used);
    return k;
}
int main(){
    for(int i = 0; i < MAX; i++){
        arr[i] = 2*i + 3;
    }

    menu();

    return 0;
}



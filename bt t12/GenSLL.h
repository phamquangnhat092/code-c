#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct product{
    char model_name[40];
    char memory[20];
    float screen;
    char price[10];
}product;

typedef struct node{
    product phone;
    node *next;
}node;

node *root, *cur, *prev;

void init_list(){
    root = NULL;
    cur = root;
}

node *makenewnode(product phone){
    node *new_ = (node*) malloc(sizeof(node));
    new_->phone = phone;
    new_->next = NULL;
    return new_;
}

//Homework I
node* insertAtPosition(node *root, product ad, int n) {
    node* p;
    int i = 0;
    for (p = root; ++i != n && p != NULL; p = p->next);
    node* new_ = makenewnode(ad);
    new_->next = (p->next == NULL) ? NULL : p->next; 
    p->next = new_;
    return new_;
}

node* deleteAtPosition(node *root, int n)  {
    node *p, *p1;
    int i = 0;
    for (p = root; ++i != n && p != NULL; p = p->next);
    p1 = p->next;
    if (p1->next != NULL) {
        p->next = p1->next;
    }
    else p->next = NULL;
    free(p1);
    return root;
}

//Homework II 
node* split(node *r, int n1, int n2) {
    int i = 0;
    node *tmp_1, *tmp_2;
    for (tmp_1 = root; ++i != n1 && tmp_1 != NULL; tmp_1 = tmp_1->next);
    r = tmp_1->next;
    for (tmp_1 = r->next; tmp_1 != NULL && ++i != n2 + n1 - 1; tmp_1 = tmp_1->next);
    tmp_2 = tmp_1->next;
    tmp_1->next = NULL;

    i = 0;
    for (tmp_1 = root; ++i != n1 && tmp_1 != NULL; tmp_1 = tmp_1->next);
    tmp_1->next = (tmp_2->next == NULL) ? NULL : tmp_2;
    return r;
}

void displaynode(node *ptr, int i){
    if(ptr == NULL){
        printf("Loi con tro NULL\n");
        return;
    }
    printf(
        "%-4d %-30s %-20s %-10.2f %-3s\n",
        i,
        ptr->phone.model_name,
        ptr->phone.memory,
        ptr->phone.screen,
        ptr->phone.price);}

product readnode() {
    product tmp;
    printf("Input model's information\n");
    printf("    - Model name (eg: Vsmart_Live_4): ");
    scanf("%s", tmp.model_name);
    printf("    - Memory (GB): ");
    scanf("%s", tmp.memory);
    printf("    - Screen (inch): ");
    scanf("%f", &tmp.screen);
    printf("    - Price ($): ");
    scanf("%s", tmp.price);
    return tmp;
}

//tạo node ở đầu danh sách
void insertathead(product e){
    node *new_ = makenewnode(e);
    new_->next = root;
    root = new_;
    cur = root;
}

//chèn sau vị trí currrent
void insertAfterCur(product e){
    node *new_ = makenewnode(e);
    if( root == NULL){
        root = new_;
        cur = root;
    }
    else if( cur == NULL) return;
    else{
        new_->next = cur->next;
        cur->next = new_;
        cur = cur->next;
    }
}

//chèn trước vị trí current
void insertBeforeCur(product e){
    node *new_ = makenewnode(e);
    if( root == NULL){
        root = new_;
        cur = root;
    }
    else{
        new_->next = cur;
        node *tmp;
        tmp = root;
        while( tmp != NULL && tmp->next!= cur && cur != NULL)
            tmp = tmp->next;
        prev = tmp;
        new_->next = cur;
        prev->next = new_;
        cur = new_;
    }
}

//in tất cả các phone trong list
void travel(node* root){
    node *p;
    int i = 0;
    printf("No   Model                          Memory               Screen     Price ($)\n");
    for( p = root; p!=NULL; p = p-> next)
        displaynode(p, ++i);
}

void deleteAtHead(){
    node *del = root;
    if( del == NULL) return;
    root = del->next;
    free(del);
    cur = root;
    prev = NULL;
}

void deleteAtCur(node* root, node *cur) {
    node *del = root;
    if (del == NULL) return;
    for (del = root; del->next != cur; del = del->next);
    del->next = cur->next;
    free(cur);
    cur = del;
}

node *find(product e){
    node *del = makenewnode(e);
    for( node *p = root; p!= NULL; p = p->next){
        if(p == del){
            cur = p;
            return p;
        }
    }
    return NULL;
}

// giải phóng list
void freeList(){
    node *to_free = root;
    while(to_free!=NULL){
        root = root->next;
        free(to_free);
        to_free = root;
    }
}

//reverse list
node *list_reverse(node *root){
    node *cur, *prev;
    cur = prev = NULL;
    while(root != NULL){
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}


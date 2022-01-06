#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct keyType{
    char name[30];
}keyType;

typedef struct Node{
    keyType key;
    struct Node* left, *right;
}nodeType;

typedef struct Node *treeType;

/*
Hàm so sánh tên:
    Input:    2 chuỗi họ và tên việt nam
              tách lấy 2 tên
              so sánh 2 tên với nhau (theo thứ tự bảng chữ cái)
    
    Out put : lớn hơn trả về 1
              bằng trả về 0
              nhỏ hơn trả về -1
*/
int vn_strcmp(char name1[], char name2[]){
    
    char *s1 = NULL, *s2 = NULL;

    char name1_tmp[20];
    char name2_tmp[20];

    strcpy(name2_tmp, name2);
    strcpy(name1_tmp, name1);

    char first_name1[10]; 
    char last_name1[10];
    char first_name2[10]; 
    char last_name2[10];

    s1 = strtok(name1_tmp,"_");
    strcpy(first_name1,s1);
    while(s1 != NULL){
        strcpy(last_name1, s1);
        s1 = strtok(NULL,"_");
    }

    s2 = strtok(name2_tmp,"_");
    strcpy(first_name2, s2);
    while(s2 != NULL){
        strcpy(last_name2, s2);
        s2 = strtok(NULL,"_");
    }
    
    if(strcmp(last_name1, last_name2) > 0) return 1;
    else if(strcmp(last_name1, last_name2) < 0) return -1;
    else{
        if(strcmp(first_name1, first_name2) > 0) return 1;
        else if (strcmp(first_name1, first_name2) < 0) return -1;
        else return 0;
    }
}

int vn_strcmp1(char name1[], char name2[]){
    
    char *s1 = NULL, *s2 = NULL;

    char name1_tmp[20];
    char name2_tmp[20];

    strcpy(name2_tmp, name2);
    strcpy(name1_tmp, name1);

    char last_name1[10];
    char last_name2[10];

    s1 = strtok(name1_tmp,"_");
    while(s1 != NULL){
        strcpy(last_name1, s1);
        s1 = strtok(NULL,"_");
    }

    s2 = strtok(name2_tmp,"_");
    while(s2 != NULL){
        strcpy(last_name2, s2);
        s2 = strtok(NULL,"_");
    }
    
    if(strcmp(last_name1, last_name2) > 0) return 1;
    else if(strcmp(last_name1, last_name2) < 0) return -1;
    else{
        return 0;
    }
}

treeType search(char model[], treeType root){
    if(root == NULL) return NULL; //not found
    else if(vn_strcmp1(root->key.name, model) == 0) 
        return root;
    else if(vn_strcmp1(root->key.name, model) < 0) return search(model,root->right);
    else{
        return search(model, root->left);
    }
}

void insertNode(keyType x, treeType *root){
    if(*root == NULL){
        (*root) = (nodeType*)malloc(sizeof(nodeType));
        (*root)->key = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (vn_strcmp(x.name , (*root)->key.name) < 0) insertNode(x, &(*root)->left);
    else if(vn_strcmp(x.name , (*root)->key.name) > 0) insertNode(x, &(*root)->right);
}

keyType deleteMin(treeType *root){
    keyType k;
    if((*root)->left == NULL){
        k = (*root)->key;
        (*root) = (*root)->right;
        return k;
    }
    else return deleteMin(&(*root)->left);
}

void deleteNode(keyType x, treeType *root){
    if(*root != NULL){
        if( vn_strcmp(x.name, (*root)->key.name) < 0) deleteNode(x, &(*root)->left);
        else if( vn_strcmp(x.name, (*root)->key.name)>0) deleteNode(x, &(*root)->right);
        else if( (*root)->left == NULL){
            *root = (*root)->right;
        }
        else if((*root)->right == NULL){
            *root = (*root)->left;
        }
        else if((*root)->left == NULL && (*root)->right == NULL){
            *root = NULL;
        }
        else{
            (*root)->key = deleteMin(&(*root)->right);
        }
    }
}

int i=1;
void LNR(treeType T){//duyệt theo thứ tự giữa( in-order)
    if(T != NULL){
        LNR(T->left);
        printf("%-4d %-30s\n",
        i++,
        T->key.name
        );
        LNR(T->right);
    }

}

void freeTree(treeType T){
    if(T != NULL){
        freeTree(T->left);
        freeTree(T->right);
        free((void*) T);
    }
}
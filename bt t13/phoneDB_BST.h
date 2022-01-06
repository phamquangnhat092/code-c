#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct keyType{
    char model_name[40];
    char memory[20];
    float screen;
    char price[10];
} keyType;

typedef struct nodeType{
    keyType key;
    nodeType* left, *right;
} nodeType;

typedef nodeType *treeType;

keyType readNode(){
    keyType tmp;
    printf("Input model's information\n");
    printf("    - Model name (eg: Oppo_Reno_6): ");
    scanf("%s", tmp.model_name);
    printf("    - Memory (GB): ");
    scanf("%s", tmp.memory);
    printf("    - Screen (inch): ");
    scanf("%f", &tmp.screen);
    printf("    - Price ($): ");
    scanf("%s", tmp.price);
    return tmp;
}


treeType search(char model[], treeType root){
    if(root == NULL) return NULL; //not found
    else if(strcmp(root->key.model_name, model) == 0) return root;
    else if(strcmp(root->key.model_name, model) < 0) 
        return search(model,root->right);
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
    else if (strcmp(x.model_name , (*root)->key.model_name) < 0) 
        insertNode(x, &(*root)->left);
    else if (strcmp(x.model_name , (*root)->key.model_name) > 0) 
        insertNode(x, &(*root)->right);
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
        if( strcmp(x.model_name, (*root)->key.model_name) < 0) 
            deleteNode(x, &(*root)->left);
        else if( strcmp(x.model_name, (*root)->key.model_name)>0) 
            deleteNode(x, &(*root)->right);
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
void LNR(treeType T)//duyet theo thu thu giua(in-order)
{
    if(T != NULL){
        LNR(T->left);
        printf("%-4d %-30s %-20s %-10.2f %-3s\n",
        i++,
        T->key.model_name,
        T->key.memory,
        T->key.screen,
        T->key.price);
        LNR(T->right);
    }
    
}

void NLR(treeType T)//duyet theo thu thu truoc(pre-order)
{
    int i = 0;
    if(T!=NULL){
        printf("%-4d %-30s %-20s %-10.2f %-3s\n",
        i++,
        T->key.model_name,
        T->key.memory,
        T->key.screen,
        T->key.price);
    NLR(T->left);  
    NLR(T->right); 
    }
}

void LRN(treeType T)//duyet theo thu thu sau(post-order)
{
    int i = 0;
    if(T!=NULL){
        LRN(T->left);
        LRN(T->right);
        printf("%-4d %-30s %-20s %-10.2f %-3s\n",
        i++,
        T->key.model_name,
        T->key.memory,
        T->key.screen,
        T->key.price);
    }
}

void freeTree(treeType T){
    if(T != NULL){
        freeTree(T->left);
        freeTree(T->right);
        free((void*) T);
    }
}



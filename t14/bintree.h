#include<stdio.h>
#include<stdlib.h>
typedef int elementype;
typedef struct Nodetype{
    elementype data;
    Nodetype *left, *right;
} Nodetype;
typedef Nodetype *bintree;
void makenullTree(bintree *t){
    *t = NULL;
}
void NLR(bintree T)//duyet theo thu thu truoc(pre-order)
{
     if(T!=NULL)
     {printf("%d   ",T->data);
      NLR(T->left);  // de quy duyet con trai
      NLR(T->right); // De quy duyet con phai
     }
}
void LNR(bintree T)//duyet theo thu thu giua(in-order)
{
     if(T!=NULL)
     {
      LNR(T->left);
      printf("%d   ",T->data);//duyet goc
      LNR(T->right);
     }
}
void LRN(bintree T)//duyet theo thu thu sau(post-order)
{
     if(T!=NULL)
     {
      LRN(T->left);
      LRN(T->right);
      printf("%d   ",T->data);
     }
}
int Emptytree(bintree t){
    return (t==NULL);
}
Nodetype *makeNewNode(elementype x){
    Nodetype *p = (Nodetype*)malloc(sizeof(Nodetype));
    p->data=x;
    p->left=p->right=NULL;
    return p;
}
bintree Leftchild(bintree l){
    if(l!=NULL) return l->left;
    else return NULL;
}
bintree Rightchild(bintree r){
    if(r!=NULL) return r->right;
    else return NULL;
}
int isLeaf(bintree t){
    if(t!=NULL) return (Leftchild(t)==NULL&&Rightchild(t)==NULL);
    else return -1;
}
int countNode(bintree t){
    if (t==NULL) return 0;
    else return (1+countNode(Leftchild(t))+countNode(Rightchild(t)));
}
bintree CreateTree(bintree p,element x)   
{   
        printf("Node: "); scanf("%d", &x);
        if (x==0)return NULL;
        p=  makeNewNode(x);
        printf("Nhap con trai cua node %d: ",x);
        p->Left=CreateTree(p->left,x);
        printf("Nhap con phai cua node %d: ",x);
        p->Right=CreateTree(p->right,x);
    return p;       
}
bintree creatfrom2tree(elementype x, bintree l, bintree r){
    bintree n= (Nodetype*)malloc(sizeof(Nodetype));
    n->data=x;
    n->left=l;
    n->right=r;
    return n;    
}
bintree Addleft(bintree *t, elementype x){
    Nodetype *n = makeNewNode(x);
    if (n==NULL) return n;
    if ((*t) == NULL) *t = n;
    else {
        Nodetype *L = *t;
        while (L->left != NULL) L=L->left;
        L->left = n;
    }
    return n;
}
bintree Addright(bintree *t, elementype x){
    Nodetype *n = makeNewNode(x);
    if (n==NULL) return n;
    if ((*t) == NULL) *t = n;
    else {
        Nodetype *R = *t;
        while (R->right != NULL) R=R->right;
        R->right = n;
    }
    return n;
}
void Free(bintree t)
{
    if ( t == NULL )
        return;
    Free( t->left );
    Free( t->right );
    free( t );
}



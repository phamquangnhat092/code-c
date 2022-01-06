#include<stdio.h>
#include<stdlib.h>
typedef int elementype;
typedef struct Nodetype{
    elementype data;
    Nodetype *left, *right;
} Nodetype;
typedef Nodetype *bst;
void makenullTree(bst *t){
    *t = NULL;
}

int LeftOf(bst t, elementype x)
{
    return x < t->data;
}
int RightOf(bst t, elementype x)
{
    return x > t->data;
}

bst Search(bst t, elementype x){
    if(t==NULL) return NULL;
    else if (t->data == x) return t;
    else if (t->data<x) return Search(t->left,x);
    else return Search(t->right,x);
}
bst InsertNode(bst t, elementype x){
    if (t == NULL) {
        t = (Nodetype*)malloc(sizeof(Nodetype));
        t->data=x;
        t->left=NULL;
        t->right=NULL;
    } else if (x<t->data) InsertNode(t->left,x);
      else if (x>t->data) InsertNode(t->right,x);
}
/*void Freetree(bintree t)
{
    if ( t == NULL )
        return;
    Freetree( t->left );
    Freetree( t->right );
    freetree( t );
}*/

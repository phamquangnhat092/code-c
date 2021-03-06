#include<stdio.h>
#include<stdlib.h>

typedef int elementType;

typedef struct nodeType{
    elementType element;
    struct nodeType *left, *right;
}nodeType;

typedef struct nodeType *treetype;
void make_null_tree(treetype *t){
    (*t) == NULL;
}

nodeType *creatnewNode(elementType data){
    nodeType *new_node = (nodeType*)malloc(sizeof(nodeType));

    new_node->element = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int emptyTree(treetype t){
    return (t==NULL);
}

treetype leftChild(treetype n){
    if(n != NULL) return n->left;
    else return NULL;
}

treetype rightChild(treetype n){
    if(n != NULL) return n->right;
    else return NULL;
}

//check leaf node
int isLeaf(treetype n){
    if(n != NULL){
        return (leftChild(n) == NULL) && (rightChild(n) == NULL);
    }
    else return -1;
}

//count node
int nb_nodes(treetype T){
    if(emptyTree(T)) return 0;
    else return 1 + nb_nodes(leftChild(T)) +nb_nodes(rightChild(T));
}

//build from 2 tree
treetype createFrom2(elementType v, treetype l, treetype r){
    treetype N = (nodeType*)malloc(sizeof(nodeType));

    N->element = v;
    N->left = l;
    N->right = r;
    return N;
}

//them vao node con trai nhat
treetype add_left(treetype *tree, elementType new_data){
    nodeType *new_node = creatnewNode(new_data);
    if(new_node == NULL){
        return new_node;
    }

    if(*tree == NULL){
        *tree = new_node;
    }
    else{
        nodeType *leftnode = *tree;
        while(leftnode->left != NULL){
            leftnode = leftnode->left;
        }
        leftnode->left = new_node;
    }

    return new_node;
}

//them vao node con phai nhat
treetype add_right(treetype *tree, elementType new_data){
    nodeType *new_node = creatnewNode(new_data);
    if(new_node == NULL){
        return new_node;
    }

    if(*tree == NULL){
        *tree = new_node;
    }
    else{
        nodeType *rightnode = *tree;
        while(rightnode->right != NULL){
            rightnode = rightnode->right;
        }
        rightnode->right = new_node;
    }

    return new_node;
}

//count leaf node
int countLeaves(treetype root){
    // n???u n??t g???c r???ng tr??? v??? 0
    if( root == NULL) return 0;

    // n???u n??t con tr??i ph???i c???a root ?????u r???ng th?? tr??? v??? 1
    if(root->left == NULL && root->right == NULL) return 1;
    // ????? quy 
    else{
        return countLeaves(root->left) +countLeaves(root->right);
    }

}

// height of tree
int height(nodeType* node)
{
    if (node == NULL)
        return -1;
    else {
        int lDepth = height(node->left);
        int rDepth = height(node->right);
 
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}


int countInterNode(treetype root){
    //n???u c?? 1 n??t return 0
    // n??t ???? c?? n??t con tr??i v?? n??t con ph???i th?? ???????c t??nh l?? n??t trong
    // ????? quy ?????n n??t con tr??i v?? ph???i c???a n??t ????

    if(root == NULL) return 0;
    int num = 0;
    if(root->left != NULL || root->right != NULL) 
    {
        num =  countInterNode(root->left) + countInterNode(root->right) + 1;
    }
    return num;
}

//?????m s??? n??t con ph???i
int countRightChild(treetype root){
    if(root == NULL) return 0;

    int num_l=0, num_r=0;
    if(root->right != NULL) num_r = countRightChild(root->right) + 1;
    if(root->left != NULL) num_l = countRightChild(root->left);

    return num_l + num_r;
    
}
//?????m s??? n??t con tr??i
int countLeftChild(treetype root){
    if(root == NULL) return 0;

    int num_l=0, num_r=0;
    if(root->left != NULL) num_l = countLeftChild(root->left) + 1;
    if(root->right != NULL) num_r = countLeftChild(root->right);

    return num_l + num_r;
    
}

void NLR(treetype T)//duyet theo thu thu truoc(pre-order)
{
     if(T!=NULL)
     {printf("%d   ",T->element);
      NLR(T->left);  // de quy duyet con trai
      NLR(T->right); // De quy duyet con phai
     }
}
void LNR(treetype T)//duyet theo thu thu giua(in-order)
{
     if(T!=NULL)
     {
      LNR(T->left);
      printf("%d   ",T->element);//duyet goc
      LNR(T->right);
     }
}
void LRN(treetype T)//duyet theo thu thu sau(post-order)
{
     if(T!=NULL)
     {
      LRN(T->left);
      LRN(T->right);
      printf("%d   ",T->element);
     }
}

void Free(treetype t)
{
    if ( t == NULL )
        return;
    Free( t->left );
    Free( t->right );
    free( t );
}
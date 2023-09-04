#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data){
    struct Node * n;
    n = (struct Node *) malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void inOrderTraversal(struct Node * root){
    if (root!=NULL)
    {
        inOrderTraversal(root->left);
        printf("%d, ", root->data);
        inOrderTraversal(root->right);
    }
    
}

struct Node * inOrderPredecessor(struct Node * root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
    
}


struct Node * deleteNode(struct Node * root, int value){
    struct Node * iPre;
    if(root==NULL){
        return NULL;
    }
    if (root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }

    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
    
    
}


int main()
{
    //Created all the nodes
    struct Node * r = createNode(4);
    struct Node * p1 = createNode(2);
    struct Node * p2 = createNode(5);
    struct Node * c1 = createNode(1);
    struct Node * c2 = createNode(3);

    //Linking the nodes just like the strucute below
    r->left = p1;
    r->right = p2;
    p1->left = c1;
    p1->right = c2;

    //In binary search tree left >> root >> right
    //The structure of this binary tree will look like
    /*
        4
      /  \
     2    5
    /  \ 
   1   3
    */

   inOrderTraversal(r);

   deleteNode(r, 4);
    printf("\n");
   inOrderTraversal(r);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int key;
    struct Node * left;
    struct Node * right;
    int height; //to check the balance mod so it will not grow more than one
};

int max(int a, int b){
    return a>b?a:b;
}

int getHeight(struct Node * n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

struct Node *createNode(int key){
    struct Node * n = (struct Node *) malloc(sizeof(struct Node));

    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int getBalanceFactor(struct Node * n){
    if(n==NULL){
        return 0;
    }
    return (getHeight(n->left) - getHeight(n->right));
}

struct Node * rightRotate(struct Node * y){
    struct Node * x = y->left;
    struct Node * T2 = x->right;

    //Check the right rotated dig for more information as we are now rotating
    x->right = y;
    y->left = T2;

    //Now for height Updation
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct Node * leftRotate(struct Node * x){
    struct Node * y = x->right;
    struct Node * T2 = y->left;

    //Check the right rotated dig for more information as we are now rotating
    y->left = x;
    x->right = T2;

    //Now for height Updation
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

struct Node * insert(struct Node * n, int key){
    if (n == NULL)
    {
        return createNode(key);
    }
    if (key < n->key)
    {
        n->left = insert(n->left, key);
    }
    else if (key > n->key)
    {
        n->right = insert(n->right, key);
   }

   n->height = 1 + max(getHeight(n->left), getHeight(n->right)); 
   int bf = getBalanceFactor(n); //storing balanceFactor
    // Left left Case
    if(bf>1 && key < n->left->key){
        return rightRotate(n);
    }
    // Right Right Case
    if(bf < -1 && key > n->right->key){
        return leftRotate(n);
    }
    // Left Right Case
    if(bf > 1 && key > n->left->key){
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    // Right Left Case
    if(bf < -1 && key < n->right->key){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
    
}

void preOrderTraversal(struct Node * root){
    if(root!=NULL){
        printf("%d, ", root->key);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main()
{
    struct Node * root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrderTraversal(root);

    return 0;
}

/*
                    y                                      x
                /     \        <<==== Left roated       /    \
              x        T3                              T1    y
            /  \               Right rotated ====>>        /   \
           T1   T2                                        T2    T3





*/

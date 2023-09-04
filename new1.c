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

int isBST(struct Node * root){
    static struct Node * prev = NULL;
    if (root!=NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);        
    }
    else{
        return 1;
    }
    
}

//Recursively
struct Node * searchBST(struct Node * root, int key){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    
    else if (root->data > key)
    {
        return searchBST(root->left, key);
    }
    else{
        return searchBST(root->right, key);
    }
    
    
}

//Main search by iterative way 
struct Node * searchIter(struct Node * root, int key){
   
    while (root!=NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        
        else if (root->data > key)
        {
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
    
    
}

//Insertion of key in binary search tree
void insert(struct Node * root, int key){
    struct Node * prev = NULL;

    while (root!=NULL)
    {
        prev = root; //previous will hold root's previous value
        if(key==root->data){ //as we are updating the roots value untill we find the spot
            printf("CAnnot insert %d already in BST", key);
            return; //prev will help in the linking as root will point at null in the last n prev to the leaf
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct Node * ptr = createNode(7);
    if (key<prev->data)
    {
        prev->left = ptr;
    }
    else{
        prev->right = ptr;
    }
    
   
    

}
//its left subtree ka rightmost child
//
struct Node * inOrderPredecessor(struct Node * root){
    root = root->left;
    while (root->right != NULL) //We are traversing to left subtree's right most child till it not null
    {
        root = root->right;
    }
    return root; //now we are reached to leaf node as we returned
    
}

//For deleting the node from the binary search tree
struct Node * deleteNode(struct Node * root, int value){
    struct Node * iPre;
    if (root==NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) //if both are null means its we reached to leaf node
    {
        free(root);//we will free the leaf node
        return NULL;
    }

    //Search the node which want to delete from the BTS
    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }//Search complete
    //Now deleltion strategy for the found node
    else{
        iPre = inOrderPredecessor(root); //this function will inorder pre val
        root->data = iPre->data; //which we will copy in the node which we are going to delete
        root->left = deleteNode(root->left, iPre->data);//now we are deleting the left node coz inorder pre will always be left
        //as it smaller then rooot and now we delete iorder pre val node as we have shifted to it the node we wanted 
        //to delete
        // in simpe steps searching left and right if small shiting inorder pre value and deleting preval                                
    }
    return root;
    }


int main()
{
    struct Node * r = createNode(4);
    struct Node * p1 = createNode(2);
    struct Node * p2 = createNode(5);
    struct Node * c1 = createNode(1);
    struct Node * c2 = createNode(3);
   

    r->left = p1;
    r->right = p2;
    p1->left = c1;
    p1->right = c2;

    inOrderTraversal(r);
    printf("\n");
    printf("%d\n", isBST(r));

    //This will return struct pointer to save it we have to store in it
    // struct Node * found = searchBST(r, 5);
    // struct Node * found = searchIter(r, 55);
    // if (found!=NULL)
    // {
    //     printf("%d\n ", found->data);      
    // }
    // else{
    //     printf("Element not found.\n"); 
    // }
    
    deleteNode(r, 4);
    inOrderTraversal(r);
    printf("ROOT is %d\n", r->data);
    


    return 0;

}

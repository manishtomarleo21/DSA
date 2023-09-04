#include<stdio.h>
#include<stdlib.h>

//Binary search tree

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

//FUnction for setting up the node
struct Node * createNode(int data){
    struct Node * n;
    n = (struct Node *) malloc(sizeof(struct Node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

//1. inOrderTraversal traversal Function for the traversal in llinked representation of the binary tree
//left subtree ===>> root ====>> right subtree   this go in recursive way 
void inOrderTraversal(struct Node * root){ //Passing a root node 

    if (root!=NULL)
    {
        inOrderTraversal(root->left); //now it will do it for the subtree and left side tree will act like tree
        printf("%d, ", root->data); //This is the oly diffrence from pre and post order traversal
        inOrderTraversal(root->right);//and will brake it till its goes null;
        //In preorder printf before recrsuive call 
        //In postorder printf after recursive call
        //In inorder print comes between both the recusive fucntion
    }
    
}

//Create a fucntion that will check the tree in binary search tree or not
int isBST(struct Node * root){
    static struct Node * prev = NULL; //static for the calls that it will not run for diffrenet calls at it will remain same
    if (root!=NULL)
    {
        if (!isBST(root->left)) //this recursice call for the left subtree
        {
            return 0; 
        }
        //Do not get confuse this only will check from to left to right the data thats its sorted
        if(prev!=NULL && root->data <= prev->data){ //this will go for the root and children as children will always 
            return 0;           //smaller then the root // basically we are checking the ascending order
        }
        prev = root; //setting the prev to root// for sunbtree the root will be the previous then parents for children 
        return(isBST(root->right)); //now recursive same for the right subtree
    }
    else{
        return 1;
    }
    
    
}

void insert(struct Node * root, int key){
    struct Node * prev = NULL;

    while (root!=NULL)
    {
        prev = root;
        if (key==root->data)
        {
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
        
    }
    struct Node * new = createNode(key);
    if (key<prev->data)
    {
        prev->left = new;
    }
    else{
        prev->right = new;
    }
    

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


//Inorder treaversal will always give the binary search tree in sorted ascending array
   inOrderTraversal(r); 
   printf("\n");
   //this will check that the tree is  BST or not if yes than it will return 1 true or if not then it will return
   //0 as false.
   printf("%d\n", isBST(r));

   insert(r, 6);
   printf("%d\n", r->right->right->data);

    
    return 0;
}

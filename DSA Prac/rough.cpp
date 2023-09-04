#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int key;
        Node* left;
        Node* right;
        int height;

        Node(int data){
            this->key = data;
            this->height = 1;
            this->left = NULL;
            this->right = NULL;
        }    
};

int getHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

// Node* createNode(int key){
//     Node* ptr = new Node(key);
//     return ptr;
// }

int getBalanceFactor(Node* root){
    if(root == NULL){
        return 0;
    }
    return (getHeight(root->left)-getHeight(root->right));

}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    y->height = max(getHeight(y->left), getHeight(y->right))+1;

    return x;

}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    y->height = max(getHeight(y->left), getHeight(y->right))+1;

    return y;

}


Node* insert(Node* root, int key){
    if(root == NULL){
        root = new Node(key);
        return root;
    }

    if(key < root->key){
        root->left = insert(root->left, key);
    }

    if(key > root->key){
        root->right = insert(root->right, key);
    }

    root->height = max(getHeight(root->left), getHeight(root->right))+1;

    int balanceFact = getBalanceFactor(root);

    if(balanceFact > 1 && key < root->left->key){
        return rightRotate(root);
    }
    if(balanceFact < -1 && key > root->right->key){
        return leftRotate(root);
    }
    if(balanceFact > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balanceFact < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; 
}

void preOrderTraversal(struct Node * root){
    if(root!=NULL){
        preOrderTraversal(root->left);
        printf("%d, ", root->key);
        preOrderTraversal(root->right);
    }
}


int main()
{
    
    Node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 2);

    preOrderTraversal(root);


    return 0;
}

void preOrderTraversal(struct Node * root){
    if(root!=NULL){
        printf("%d, ", root->key);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
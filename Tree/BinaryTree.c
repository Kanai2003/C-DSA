#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

// Inorder traversal
void inorderTraversal( node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ->", root->data);
    inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal( node* root) {
    if (root == NULL) return;
    printf("%d ->", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->data);
}

// Create a new Node
node *createNode( int value) {
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


// Insert on the right of the node
node *insertRight(node* root, int value) {
    root->right = createNode(value);
    return root->right;
}

//Insert a node in a Binary tree
void insertInBST(node ** root, int val){
    if(*root == NULL){
        *root = createNode(val);
    }else{
        if((*root)->data > val){
            insertInBST(&((*root)->left),val);
        }else{
            insertInBST(&((*root)->right), val);
        }
    }
}


//Check if a tree is BST or not
int isBST(node * root){
    static node *prev=NULL;
    if(root == NULL){
        return 1;
    }else{
        if(! isBST(root->left)){
            return 0;
        }
        if(prev != NULL && prev->data >= root->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
}


int main() {
    node* root = createNode(3);
    insertInBST(&root, 5);
    insertInBST(&root, 1);
    insertInBST(&root, 4);
    insertInBST(&root, 2);

    printf("Inorder traversal \n");
    inorderTraversal(root);

    printf("\nPreorder traversal \n");
    preorderTraversal(root);

    printf("\nPostorder traversal \n");
    postorderTraversal(root);

    printf("\nis BST : %d",isBST(root));
    printf("\nis BST : %d",BSTAnother(root));

}

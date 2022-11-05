#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;
//creat a node using value and return it
node * init(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}
// Inorder traversal
void inorder(node * root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
// Preorder traversal
void preorder(node *root){
    if(root == NULL){
        return ;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
//Postorder traversal
void postorder(node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
//insert a value in BST 
void insert(node **root,int val){
    if((*root) == NULL){
        *root = init(val);
        return ;
    }
    if((*root)->data > val){
        insert(&((*root)->left), val);
    }else{
        insert(&((*root)->right),val);
    }
}
/* search and returns the node to be deleted, address of 
its parent and wheather the node is found or not */
void search(node ** root, int val, node ** parent , node **x, int *found){
    node * temp = *root;
    *parent = NULL;
    *found = 0;
    while(temp != NULL){
        //if the node to be deleted is found
        if(temp->data == val){ 
            *x = temp;
            *found = 1;
            return ;
        }
        *parent = temp;
        if(temp->data > val){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
}
// delete a node from the BST
void delete(node **root, int val){
    node * parent, *x, *xsucc;
    int found;
    // if tree is empty
    if (*root == NULL){
        printf("\nTree is Empty ");
        return;
    }
    parent = x = NULL;
    // search the element
    search(root,val,&parent,&x,&found);
    // if not found 
    if (found == 0){
        printf("\nData to be deleted, not found");
        return;
    }
    // two chld is present
    /* here I'm just changing the value of the node to be deleted 
    with its successor and setting the successor to be deleted as 'x' */
    if(x->left!=NULL && x->right!=NULL){
        parent = x;
        xsucc = x->right;
        while(xsucc->left != NULL){
            parent = xsucc;
            xsucc = xsucc->left;
        }
        x->data = xsucc->data;
        x = xsucc;
    }
    // no child is present
    if(x->left==NULL && x->right==NULL){
        if(parent->left == x){
            parent->left == NULL;
        }else{
            parent->right = NULL;
        }
        free(x);
        return ;
    }
    //only right chile is present 
    if(x->left==NULL && x->right!=NULL){
        if(parent->left == x){
            parent->left = x->right;
        }else{
            parent->right = x->right;
        }
        free(x);
        return;
    }
    //only left child is present
    if(x->left!=NULL && x->right==NULL){
        if(parent->left == x){
            parent->left = x->left;
        }else{
            parent->right = x->left;
        }
        free(x);
        return;
    }
}
int main(){
    node *root = NULL;
    insert(&root,6);
    insert(&root,4);
    insert(&root,2);
    insert(&root,1);
    insert(&root,3);
    insert(&root,5);
    insert(&root,8);
    insert(&root,7);
    insert(&root,9);
    printf("Inorder : \n");
    inorder(root);
    delete(&root,6);
    printf("\nInorder : \n");
    inorder(root);

    return 0;
}
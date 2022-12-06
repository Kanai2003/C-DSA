#include<stdio.h>
#include<stdlib.h>

enum boolean{
    false = 0,
    true = 1
};

typedef struct thtree{
    enum boolean isleft;   //is left pointer a thread pointer
    struct thtree *left;
    int data;
    struct thtree *right;
    enum boolean isright;  //is right pointer a thread pointer
}thtree;

void insert( thtree **root, int val){

    thtree *ptr,*newNode,*head=*root;

    // allocating a new node 
    newNode = (thtree*)malloc(sizeof(thtree));
    newNode->isleft = true;
    newNode->isright = true;
    newNode->data = val;

    if((*root) == NULL){
        head = (thtree*)malloc(sizeof(thtree));

        head->data = -9999;
        head->isleft = false;
        head->left = newNode;
        head->isright = false;
        head->right = head;

        *root = head;
        newNode->left = head;
        newNode->right = head; 
    }else{
        ptr = head->left;

        // traverse till the thread is found attached to the head
        while(ptr != head){
            if(val < ptr->data){

                if(ptr->isleft == true){
                    newNode->left = ptr->left;
                    ptr->left = newNode;
                    ptr->isleft = false;
                    newNode->right = ptr;
                    // newNode->isright = true;
                    return;
                }else{
                    ptr = ptr->left;
                }
            }else{
                if(ptr->isright == true){
                    newNode->right = ptr->right;
                    ptr->isright = false;
                    ptr->right = newNode;
                    newNode->left = ptr;
                    // newNode->isleft = true;
                    return ;
                }else{
                    ptr = ptr->right;
                }
            }
        }
    }
}
void search(thtree **root,int val, thtree **x,thtree **par, int *found){
    thtree *p = (*root)->left;
    *found = false;
    *par = NULL;

    while(p != *root){
        if(p->data == val){   //if the node to be deleted is found
            *found = true;
            *x = p;
            return;
        }
        *par = p;
        if(val < p->data){
            if(p->isleft == true){  //for most left/smallest element
                *found = false;
                x = NULL;
                return ;
            }
            p = p->left;
        }else{
            if(p->isright == true){  //for most right/largest element
                *found = false;
                x = NULL;
                return ;
            }
            p = p->right;
        }
    }
}
void delete(thtree** root , int val){
    if(*root == NULL){
        printf("\nTree is empty");
        return;
    }
    int found ;
    thtree  *x = NULL, *parent = NULL, *xsucc; 

    // search the element
    search(root,val,&x,&parent,&found);
    if(found == false){
        printf("Data to be deleted, not found\n");
        return;
    }
    //if the node to be deleted has two children
    if(x->isleft == false && x->isright == false){
        parent = x;
        xsucc = x->right;
        while(xsucc->isright == false){
            parent = xsucc;
            xsucc = xsucc->right;
        }
        x->data = xsucc->data;
        x = xsucc;
    }
    //if the node to be deleted has no children
    if(x->isleft == true && x->isright == true){
        //if the node to be deleted is a root node
        if(parent == NULL){
            (*root)->left = *root;
            (*root)->isleft = true;
            free(x);
            return ;
        }
        if(parent->left == x){
            parent->left = x->left;
            parent->isleft = true;
        }else{
            parent->right = x->right;
            parent->isright = true;
        }
        free(x);
        return ;
    }
    //if the node to be deleted has only left child
    if(x->isleft == false  && x->isright == true){
        //the node to be deletes is a root node 
        if(parent == NULL){
            parent = x;
            xsucc = x->left;
            while(xsucc->right == false){
                xsucc = xsucc->right;
            }
            xsucc->right = *root;
            (*root)->left = x->left;
            free(x);
            return ;
        }
        if(parent->left == x){
            parent->left = x->left;
            x->left->right = x->right;
        }else{
            parent->right = x->left;
            x->left->right = x->right;
        }
        free(x);
        return;
    }
    //if the node to be deletes has only right child
    if(x->isleft == true && x->isright == false){
        //node to be deletes is a root node
        if(parent == NULL){
            (*root)->left = x->right;
            free(x);
            return ;
        }
        if(parent->left == x){
            parent->left = x->right;
            x->right->left = x->left;
        }else{
            parent->right = x->right;
            x->right->left = parent;
        }
        free(x);
        return ;
    }
}
void inorder(thtree *root){
    thtree *p = root->left;
    while(p != root){
        while(p->isleft == false){
            p = p->left;
        }
        printf("%d ", p->data);
        while(p->isright == true){
            p = p->right;
            if(p == root){
                break;
            }
            printf("%d ",p->data);
        }
        p = p->right;
    }
    printf("\n");
}
int main(){
    thtree *root = NULL;
    insert(&root,5);
    insert(&root,3);
    insert(&root,6);
    insert(&root,2);
    insert(&root,8);
    inorder(root);
    delete(&root,5);
    inorder(root);

}
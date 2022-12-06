#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
    int height;
}node;

int max(int a, int b){
    return a>b?a:b;
}
int getHeight(node *n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}

// to creat a node 
node * init(int key){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
}

int getBalanceFactor(node *n){
    if (n == NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

/* rotation of a tree:

          y           ==>Right rotate==>       x   
        /   \                                /  \
        x    t3       <== Left rotate<==   t1    y
       / \                                      / \
      t1  t2                                  t2  t3

*/
node * rightRotate(node *y){
    node * x = y->left;
    node * t2 = x->left;
    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
} 

node * leftRotate(node *x){
    node * y = x->right;
    node * t2 = y->left;
    y->left = x;
    x->right = t2; 

    y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return y;
} 

node *insert(node*n, int key){
    if(n == NULL){
        return init(key);
    }
    if(key < n->key){
        n->left = insert(n->left,key);
    }else if(key > n->key){
        n->right = insert(n->right,key);
        return n;
    }
    n->height = 1 + max(getHeight(n->left),getHeight(n->right));
    int bf = getBalanceFactor(n);

    //left left case 
    if(bf > 1 && key< n->left->key){
        return rightRotate(n);
    }
    //right right case
    if(bf < -1 && key > n->right->key){
        return leftRotate(n);
    }
    //left right case
    if(bf>1 && key> n->right->key){
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    //right left case
    if(bf<-1 && key>n->right->key){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}

void preOrder(node * root){
    if(root == NULL){
        return ;
    }
    printf(" %d ",root->key);
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    node * root = NULL;
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,3);

    preOrder(root);
    return 0;
}

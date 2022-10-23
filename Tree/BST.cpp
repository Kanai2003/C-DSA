//Program to check if the given Tree is BST (Binary Search Tree). 

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isBST(TreeNode* root, long min, long max){
    if(!root)   return true;
    if(root->val <= min || root->val >= max)  return false;
    return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
}

bool checkBST(TreeNode* root) {
    return isBST(root, LONG_MIN, LONG_MAX);
}


int main(){

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    if(checkBST(root)) cout<<"Given tree is a BST";
    else cout<<"Given tree is not a BST";


    return 0;
}



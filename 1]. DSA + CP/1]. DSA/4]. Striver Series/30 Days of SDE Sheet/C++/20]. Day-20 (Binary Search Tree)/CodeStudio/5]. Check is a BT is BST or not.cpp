#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool checkBST(BinaryTreeNode<int>* root, int mn, int mx)
{
    if(root==NULL)
        return true;
    if(root->data>=mn && root->data<=mx)
        return checkBST(root->left,mn,root->data)&&checkBST(root->right,root->data,mx);
    else
        return false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return checkBST(root,INT_MIN,INT_MAX);  
}
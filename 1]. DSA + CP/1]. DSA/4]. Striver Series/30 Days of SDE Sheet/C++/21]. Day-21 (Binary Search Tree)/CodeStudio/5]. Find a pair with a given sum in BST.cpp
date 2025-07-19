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

/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>

bool dfs(BinaryTreeNode<int>* root, unordered_set<int>& set, int k){
    if(root == NULL)return false;
    if(set.count(k - root->data))return true;
    set.insert(root->data);
    return dfs(root->left, set, k) || dfs(root->right, set, k);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k){
    // Write your code here
    unordered_set<int> set;
    return dfs(root, set, k);
}
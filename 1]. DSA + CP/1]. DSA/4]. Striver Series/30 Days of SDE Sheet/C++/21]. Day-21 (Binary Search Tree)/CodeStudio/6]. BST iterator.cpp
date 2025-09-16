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

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include<bits/stdc++.h>
class BSTiterator
{
    public:
    stack<TreeNode<int>*> order;
    BSTiterator(TreeNode<int>*root)
    {
        // write your code here
        inorder(root);
    }
    
    void inorder(TreeNode<int>* root){
        while(root != NULL){
            order.push(root);
            root = root->left;
        }    
    }

    int next()
    {
        // write your code here
        TreeNode<int>* topi = order.top();
        order.pop();
        inorder(topi->right);
        return topi->data;
    }

    bool hasNext()
    {
        // write your code here
        return !order.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
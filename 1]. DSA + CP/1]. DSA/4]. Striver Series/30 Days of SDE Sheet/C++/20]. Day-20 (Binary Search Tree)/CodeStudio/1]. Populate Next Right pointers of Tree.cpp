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

/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<bits/stdc++.h>

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(root==NULL)
        return;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            BinaryTreeNode<int> *temp=q.front();
            q.pop();
            
            if(i==n-1)
                temp->next=NULL;
            else
                temp->next=q.front();
            
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }
}

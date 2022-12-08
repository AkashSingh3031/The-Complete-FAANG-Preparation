/*
Following is the structure of Tree Node

class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/
#include<bits/stdc++.h>
vector<int> preorderTraversal(TreeNode* root)
{
    // Write your code here	
    stack<TreeNode*> nodeStack;
    vector<int> result;
    //base case
    if(root==NULL)
        return result;
    nodeStack.push(root);
    while(!nodeStack.empty())
    {
        TreeNode* node= nodeStack.top();
        result.push_back(node->val);
        nodeStack.pop();
        if(node->right)
            nodeStack.push(node->right);
        if(node->left)
            nodeStack.push(node->left);
    }
    return result;
}
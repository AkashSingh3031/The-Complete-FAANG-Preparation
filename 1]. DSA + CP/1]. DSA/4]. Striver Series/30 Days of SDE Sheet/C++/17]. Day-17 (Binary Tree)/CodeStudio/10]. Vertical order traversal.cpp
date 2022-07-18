/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    // Write your code here.
    vector<int>give;
    map<int,map<int,vector<int>>> nodes;
    queue<pair<TreeNode<int>*,pair<int,int>>>q;
    if(root == nullptr) return give;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p= q.front();
        q.pop();
        TreeNode<int>* temp = p.first;
        int x = p.second.first;
        int y= p.second.second;
        nodes[x][y].push_back(temp->data) ;
        if(temp->left){
            q.push({temp->left,{x-1,y+1}});
        }
        if(temp->right){
            q.push({temp->right,{x+1,y+1}});
        }
    }
    
    vector<vector<int>> ans;
    for(auto it : nodes){
        vector<int> col;
        for(auto p : it.second){
            col.insert(col.end(),p.second.begin(),p.second.end());
        }
        ans.push_back(col);
    }
    
    for(auto it : ans){
        for(auto p : it){
            give.push_back(p);
        }
    }
    return give;
   
}
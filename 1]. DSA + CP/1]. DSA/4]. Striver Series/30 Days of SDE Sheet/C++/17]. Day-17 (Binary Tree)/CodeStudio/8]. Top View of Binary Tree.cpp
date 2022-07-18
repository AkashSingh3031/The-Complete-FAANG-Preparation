/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
using namespace std;

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int>ans;
    if(root==NULL)
        return ans;
    
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    map<int,int>mp;
    
    while(!q.empty())
    {
        TreeNode<int>*temp=q.front().first;
        int dist=q.front().second;
        q.pop();
        
        if(mp.count(dist)==0)
            mp[dist]=temp->val;        
        if(temp->left!=NULL)
            q.push({temp->left,dist-1});
        if(temp->right!=NULL)
            q.push({temp->right,dist+1});
    }
    
    for(auto i:mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
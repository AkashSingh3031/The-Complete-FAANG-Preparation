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
bool helper(TreeNode<int> *root, TreeNode<int> *leaf,stack<TreeNode<int>*> &st){
    st.push(root);
    if(!root->left && !root->right){
        if(root->data==leaf->data)
            return true;
        else{
            st.pop();return false;
        }
    }
    if(root->left){
    if(helper(root->left,leaf,st)) return true;}
    if(root->right){
    if(helper(root->right,leaf,st)) return true;}
    st.pop(); return false;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	// Write your code here.
    if(!root)
        return NULL;
    stack<TreeNode<int> *> st;
    bool f=helper(root,leaf,st);
    TreeNode<int> *new_root=st.top();
    st.pop();
    TreeNode<int> *par=new_root;
    while(!st.empty()){
        auto cur=st.top();
        st.pop();
        if(cur->left==par){
            cur->left=NULL;
            par->left=cur;
        }
        else{
            cur->right=cur->left;
            cur->left=NULL;
            par->left=cur;
        }
        par=cur;
    }
    return new_root;
}

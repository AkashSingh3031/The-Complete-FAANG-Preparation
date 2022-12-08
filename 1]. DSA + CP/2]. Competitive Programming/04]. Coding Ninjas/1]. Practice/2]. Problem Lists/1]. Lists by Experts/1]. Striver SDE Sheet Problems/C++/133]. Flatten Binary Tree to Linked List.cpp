/************************************************************

    Following is the TreeNode class structure.

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
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(!root)return root;
    stack<TreeNode<int> *> st;
    st.push(root);
    TreeNode<int> * cur=root;
    TreeNode<int>* r=cur;
    while(!st.empty()){
        cur=st.top();
        st.pop();
        if(cur->right)st.push(cur->right);
        if(cur->left)st.push(cur->left);
        if(!st.empty())cur->right=st.top();
        cur->left=NULL;
    }
    return r;
}
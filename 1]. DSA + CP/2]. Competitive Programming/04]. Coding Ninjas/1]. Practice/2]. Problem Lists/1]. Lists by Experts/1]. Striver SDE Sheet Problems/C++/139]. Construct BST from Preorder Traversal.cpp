/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* bstFromInorder(int s, int e, vector<int>& inorder) {
    if(s>e)
        return NULL;

    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(inorder[mid]);
    root->left = bstFromInorder(s, mid-1, inorder);
    root->right = bstFromInorder(mid+1, e, inorder);

    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preorder){
    // Write your code here.
    sort(preorder.begin(), preorder.end());
    return bstFromInorder(0, preorder.size()-1, preorder);
}
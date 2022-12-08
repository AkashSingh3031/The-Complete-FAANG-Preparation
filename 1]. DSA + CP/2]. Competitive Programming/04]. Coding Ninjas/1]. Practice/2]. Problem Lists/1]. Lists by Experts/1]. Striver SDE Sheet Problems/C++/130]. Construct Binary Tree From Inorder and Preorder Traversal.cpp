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
TreeNode<int>* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
    if (left > right) return NULL;
    int pivot = left;
    while(inorder[pivot] != preorder[rootIdx]) pivot++;

    rootIdx++;
    TreeNode<int>* newNode = new TreeNode<int>(inorder[pivot]);
    newNode->left = build(preorder, inorder, rootIdx, left, pivot-1);
    newNode->right = build(preorder, inorder, rootIdx, pivot+1, right);
    return newNode;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int rootIdx = 0;
    return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
}
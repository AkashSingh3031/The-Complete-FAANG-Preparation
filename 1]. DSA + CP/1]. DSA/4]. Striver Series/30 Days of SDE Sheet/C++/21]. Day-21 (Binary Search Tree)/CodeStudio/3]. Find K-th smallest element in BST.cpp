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
int ans;
void inorder(TreeNode<int>* root, int& k) {
    if (!root) return;
    inorder(root->left, k);
    if (--k == 0){
        ans = root->data;
        return;
    } 
    inorder(root->right, k);
}
   
int kthSmallest(TreeNode<int> *root, int k)
{
    inorder(root, k);
    return ans;
}
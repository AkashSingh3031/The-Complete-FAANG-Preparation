/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
/*<........................ Approach - 01 .............................>
    
    void preorder(TreeNode *root, vector<int> &ans){
        
         if(root == NULL) 
            return;
        
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
        
    }

    vector<int> preorderTraversal(TreeNode* root){
        
        vector<int> ans;
    
        preorder(root,ans);
        return ans;
 */
 
        
//<........................ Approach - 02 .............................>
  
        vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root){
        
        if(root == NULL) return {};
        
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        
        return ans;
    
    }
};
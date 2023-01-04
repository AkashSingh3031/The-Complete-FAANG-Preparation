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
    
    /* <............... Approach - 01 ..........................>
    
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(root == NULL) return {};
        
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        
        return ans;
      
     */
    
  //<................. Approach - 02 ................................>  
    
     void postorder(TreeNode *root, vector<int> &ans){
         
         if(root == NULL )
             return;
         
         postorder(root->left,ans);
         postorder(root->right,ans);
         ans.push_back(root->val);
         
     }
    
     vector<int> postorderTraversal(TreeNode* root) {
         
         vector<int> ans;
         postorder(root,ans);
         return ans;
        
    }
};
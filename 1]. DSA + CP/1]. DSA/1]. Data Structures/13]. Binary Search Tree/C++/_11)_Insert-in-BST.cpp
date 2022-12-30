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
    
//<............... Iterative Solution .......................>
    
 TreeNode* insertIntoBST(TreeNode* root, int val) {
       
     TreeNode *temp = new TreeNode(val);
     TreeNode *curr = root, *parent = NULL;
     
     while(curr != NULL){
         parent = curr;
         
         if(curr->val > val){
             curr = curr -> left;
         }else if(curr->val < val){
             curr = curr -> right;
         }else{
             return root;
         }        
     }
       
     if(parent == NULL){
         return temp;
     }
     
     if(parent->val > val){
         parent->left = temp;
     }else if(parent->val < val){
         parent->right = temp;
     }
      
     return root;
    }
};

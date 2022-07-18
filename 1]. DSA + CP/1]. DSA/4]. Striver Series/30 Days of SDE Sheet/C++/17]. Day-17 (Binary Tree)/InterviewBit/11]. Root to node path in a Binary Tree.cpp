/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int>g;
void f(TreeNode* A,int B,vector<int>v)
{
    if(A==0)
        return ;
    v.push_back(A->val);
    if(B==A->val)
    {
        g=v;
        return ;
    }
    f(A->left,B,v);
    f(A->right,B,v);
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    f(A,B,ans);
    return g;
}

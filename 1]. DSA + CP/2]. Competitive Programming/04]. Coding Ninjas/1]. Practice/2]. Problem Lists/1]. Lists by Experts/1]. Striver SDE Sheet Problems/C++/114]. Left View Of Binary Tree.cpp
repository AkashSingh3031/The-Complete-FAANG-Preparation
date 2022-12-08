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
void solve(TreeNode<int>* root,vector<int> &ans,int level){
    if(root==NULL)
        return;
    
    if(ans.size()==level)
        ans.push_back(root->data);
    
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    // Write your code here
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}
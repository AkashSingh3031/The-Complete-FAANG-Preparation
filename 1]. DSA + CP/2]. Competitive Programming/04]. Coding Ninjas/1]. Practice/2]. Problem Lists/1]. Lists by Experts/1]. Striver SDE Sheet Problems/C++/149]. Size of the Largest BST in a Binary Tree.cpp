/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
vector<int> largeBST(TreeNode<int>* root)
{
    if(root==NULL)
        return {0,INT_MAX,INT_MIN};
    vector<int> l=largeBST(root->left);
    vector<int> r=largeBST(root->right);
    if(l[2]< root->data && root->data<r[1])
        return {1+l[0]+r[0],min(l[1],root->data),max(r[2],root->data)};
    else
        return {max(l[0],r[0]),INT_MIN,INT_MAX};
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    vector<int> temp=largeBST(root);
    return temp[0];
}

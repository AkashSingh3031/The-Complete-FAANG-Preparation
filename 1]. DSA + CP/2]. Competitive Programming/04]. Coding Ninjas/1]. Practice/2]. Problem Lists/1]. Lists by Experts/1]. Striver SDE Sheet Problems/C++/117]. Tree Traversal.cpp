/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void inorder(BinaryTreeNode<int> *root,vector<int>&in)
{
    if(root==NULL)
        return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
    return;
}
void preorder(BinaryTreeNode<int> *root,vector<int>&pre)
{
    if(root==NULL)
        return;
    pre.push_back(root->data);
    preorder(root->left,pre);
    preorder(root->right,pre);
    return;
}
void postorder(BinaryTreeNode<int> *root,vector<int>&post)
{
    if(root==NULL)
        return;
    postorder(root->left,post);
    postorder(root->right,post);
    post.push_back(root->data);
    return;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> arr;
    vector<int>in;
    vector<int>pre;
    vector<int>post;
    inorder(root,in);
    preorder(root,pre);
    postorder(root,post);
    arr.push_back(in);
    arr.push_back(pre);
    arr.push_back(post);
    return arr;
}
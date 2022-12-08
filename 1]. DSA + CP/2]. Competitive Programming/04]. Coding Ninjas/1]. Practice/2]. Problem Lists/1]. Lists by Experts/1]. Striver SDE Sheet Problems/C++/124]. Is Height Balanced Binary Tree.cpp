/*************************************************************
 
    Following is the Binary Tree node structure

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

*************************************************************/
bool ans;
int checkBalance(BinaryTreeNode<int>* root){
    if(!root)
        return 0;
    if(!ans)
        return 0;
    int leftSubTree = checkBalance(root->left);
    int rightSubTree = checkBalance(root->right);
    if(abs(leftSubTree-rightSubTree) > 1){
        ans = false;
    }
    return 1 + max(leftSubTree, rightSubTree);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    ans = true;
    int temp = checkBalance(root);
    return ans;
}
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

int solve(TreeNode<int> *root,int &dia){
    if(!root)return -1;
    int left=1+solve(root->left,dia);
    int right=1+solve(root->right,dia);
    dia=max(dia,left+right);
    return max(left,right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int dia=0;
    solve(root,dia);
    return dia;
}
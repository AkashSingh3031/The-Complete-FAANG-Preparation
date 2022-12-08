/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void inorder_predecessor(BinaryTreeNode<int>* root,int &pred, int key)
{
    while(root!=NULL)
    {
        if(root->data<key)
        {
            pred=root->data;
            root=root->right;
        }
        else if(root->data>=key)
        {
            root=root->left;
        }
    }
}
void inorder_successor(BinaryTreeNode<int>* root,int &succ, int key)
{
    while(root!=NULL)
    {
        if(root->data>key)
        {
            succ=root->data;
            root=root->left;
        }
        else if(root->data<=key)
        {
            root=root->right;
        }
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.

    int pred=-1;
    int succ=-1;
    
    inorder_predecessor(root,pred,key);
    inorder_successor(root,succ,key);
    
    pair<int,int>ans= {pred,succ};
    return ans;
}

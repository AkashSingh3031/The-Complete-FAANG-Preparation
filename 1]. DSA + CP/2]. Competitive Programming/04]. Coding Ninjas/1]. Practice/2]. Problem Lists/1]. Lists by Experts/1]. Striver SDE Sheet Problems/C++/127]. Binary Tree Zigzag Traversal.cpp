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

#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL) return ans;
    queue<BinaryTreeNode<int> *> q;
        q.push(root);
        
        bool leftToRight=true;
        
        while(!q.empty()) {
            int size=q.size();
            vector<int> row(size);
            
            for(int i=0; i<size; i++) {
                BinaryTreeNode<int> * node=q.front();
                q.pop();
                
                int index=leftToRight?i:(size-1-i);
                
                row[index]=node->data;
                if(node->left != NULL) 
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
            leftToRight = !leftToRight;
            for(int i=0; i<row.size(); i++) {
                ans.push_back(row[i]);
            }
        }
        return ans;
}
 int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        
        int depth=0;
        int i;
        q.push(root);
        if(root!=NULL)
        {
        while(!q.empty())
        {
            int size=q.size();
            
         for(i=0;i<size;i++)
         {
             TreeNode*temp=q.front();
             q.pop();
             if(temp->left)
             {
                 q.push(temp->left);
             }
             if(temp->right)
             {
                 q.push(temp->right);
             }
         }
            depth++;
             
         }
        }
        return depth;
        
    }

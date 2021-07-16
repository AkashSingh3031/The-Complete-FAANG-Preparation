 vector<int> rightSideView(TreeNode* root) {
        
        
        vector<int>v1;
        vector<int>v;
         TreeNode* temp;
        int i;
        queue<TreeNode*>q;
        if(root!=NULL)
        {
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            v.clear();
            for(i=0;i<size;i++)
            {
               
             temp=q.front();
             v.push_back(temp->val);
            if(temp->left!=NULL)
            {
            q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
            q.push(temp->right);
                
            }
                q.pop();
            }
            v1.push_back(v[size-1]);
            
          
          
          
        }
        
        }
        return v1;
        
    }

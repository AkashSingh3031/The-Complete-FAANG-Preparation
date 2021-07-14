 int minDepth(Node *root) {
        // Your code here
     queue<Node*>q;
        
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
             Node*temp=q.front();
             q.pop();
             if(temp->left)
             {
                 q.push(temp->left);
             }
             if(temp->right)
             {
                 q.push(temp->right);
             }
             if(temp->right==NULL && temp->left==NULL)
             {
                 return depth+1;
             }
         }
            depth++;
             
         }
        }
       
        
    
       
    }
     

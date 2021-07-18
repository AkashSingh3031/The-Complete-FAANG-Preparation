vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>v1;
        vector<int>v;
         Node* temp;
        int i;
        queue<Node*>q;
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
             v.push_back(temp->data);
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
            v1.push_back(v[0]);
            
          
          
          
        }
        
        }
        return v1;
   
}

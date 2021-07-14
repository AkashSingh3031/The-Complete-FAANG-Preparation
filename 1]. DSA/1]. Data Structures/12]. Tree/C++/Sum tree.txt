 int add(Node*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int sum=root->data+add(root->left)+add(root->right);
        return sum;
       
        
        
    }
    bool isSumTree(Node* root)
    {
         // Your code here
       
         
         if(root==NULL)
         {
             return 1;
         }
         if(root->left==NULL && root->right==NULL)
         {
             return 1;
         }
        int leftsum= add(root->left);
        
         int rightsum=add(root->right);
         
        int total=leftsum+rightsum;
        
        if(total==root->data)
        {
            
            
            if((isSumTree(root->left))&& (isSumTree(root->right)))
            {
                return 1;
            }
           
              
        }
         return 0;
      
         
    }
   

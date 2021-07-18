int height(struct Node* node){
        // code here 
        int h;
        if(node==NULL)
        {
            return 0;
        }
        
        int left= height(node->left);
        int right=height(node->right);
        
        if(left>right)
        {
            h=left+1;
        }
        else if(right>=left)
        {
            h=right+1;
        }
        return h;
    }

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    //  Your Code here
    if(root==NULL)
    {
        return 1;
    }
    int l,r,h1,h2;
   
      l=height(root->left);
      r=height(root->right);
      
     
   if(abs(l-r)<=1 && isBalanced(root->left)&& isBalanced(root->right))
   {
       return 1;
   }

   
   return 0;
 
    
    
    
}

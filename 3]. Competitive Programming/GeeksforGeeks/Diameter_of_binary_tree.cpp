 int height(Node* node){
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
    int diameter(Node* root) {
        // Your code here
        if(root==NULL)
        {
            return 0;
        }
        
        
        int lheight= height(root->left);
        int rheight=height(root->right);
        int ldiameter= diameter(root->left);
        int rdiameter=diameter(root->right);
        
        int res= max(lheight+rheight+1, max(ldiameter,rdiameter));
        return res;
        
    }

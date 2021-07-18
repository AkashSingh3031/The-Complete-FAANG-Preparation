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

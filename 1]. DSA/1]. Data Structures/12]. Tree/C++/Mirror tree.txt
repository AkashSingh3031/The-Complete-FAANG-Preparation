  void mirror(Node* node) {
        // code here
        if(node==NULL)
        {
            return;
        }
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
        
        
        
        
        
        
    }

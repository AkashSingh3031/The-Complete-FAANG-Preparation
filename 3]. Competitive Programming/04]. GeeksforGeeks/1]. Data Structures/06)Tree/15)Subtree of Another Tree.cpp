  bool identical(TreeNode*root,TreeNode*subRoot)
    {
        if(root==NULL&&subRoot==NULL)
        {
            return 1;
        }
       
        if(root!=NULL && subRoot!=NULL)
        {
            if((root->val==subRoot->val) && (identical(root->left,subRoot->left))&&(identical(root->right,subRoot->right)))             
            {
                   return 1;
               }
        }
               return 0;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root==NULL)
        {
            return 0;
        }
        if(subRoot==NULL)
        {
            return 1;
        }
        
        if(identical(root,subRoot))
        {
            return 1;
        }
        if(root!=NULL && subRoot!=NULL)
        {
            if((isSubtree(root->left,subRoot))||(isSubtree(root->right,subRoot)))
               {
                   return 1;
               }
        }
               return 0;
        
    }

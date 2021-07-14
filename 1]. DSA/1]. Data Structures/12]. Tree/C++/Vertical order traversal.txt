 vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>>p;
        map<int,vector<int>>m;
        int hd=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,hd});
        if(root!=NULL)
        {
            
            while(!q.empty())
            {
                pair<TreeNode*,int>temp= q.front();
                 q.pop();
                hd=temp.second;
                  TreeNode* node =temp.first;
                m[hd].push_back(node->val);
                if(node->left!=NULL)
                {
                    q.push({node->left,hd-1});
                }
                if(node->right!=NULL)
                {
                     q.push({node->right,hd+1});
                }
               
                
            }
            vector<int>t;
           
            for(auto it=m.begin();it!=m.end();it++)
            {
                t.clear();
                 
                for(int i=0;i<it->second.size();i++)
                {
                    t.push_back(it->second[i]);
                }
                sort(t.begin(),t.end());
                p.push_back(t);
            }
            
            
        }
        return p;
    }

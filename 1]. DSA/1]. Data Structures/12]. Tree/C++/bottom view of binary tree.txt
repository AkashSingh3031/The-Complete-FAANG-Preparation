 vector <int> bottomView(Node *root) {
        // Your Code Here
        
        
        
        
    vector<int>p;
        map<int,vector<int>>m;
        int hd=0;
        queue<pair<Node*,int>>q;
        q.push({root,hd});
        if(root!=NULL)
        {
            
            while(!q.empty())
            {
                pair<Node*,int>temp= q.front();
                 q.pop();
                hd=temp.second;
                  Node* node =temp.first;
                m[hd].push_back(node->data);
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
               
                p.push_back(t[t.size()-1]);
            }
            
            
        }
    
        return p;
    }

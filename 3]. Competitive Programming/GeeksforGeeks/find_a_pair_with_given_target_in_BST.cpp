 ques-find the nodes whose sum is equal to given target
 algorithm=step1: level order traversal
           step2: two pointer algorithm
 
 
 
 int isPairPresent(struct Node *root, int target)
    {
        queue<Node*>q;
        if(root!=NULL)
        {
        q.push(root);
        }
        Node*temp;
      
        int sum;
        vector<int>v;
        while(!q.empty())
        {
            temp=q.front();
            v.push_back(temp->data);
           q.pop();
           if(temp->left!=NULL)
           {
               q.push(temp->left);
           }
           if(temp->right!=NULL)
           {
               q.push(temp->right);
           }
        }
        sort(v.begin(),v.end());
        int i=0;
        int j=v.size()-1;
        
        while(i<j)
        {
            
            if(v[i]+v[j]<target)
            {
                i++;
            }
            else if(v[i]+v[j]>target)
            {
                j--;
            }
            else if(v[i]+v[j]==target)
            {
                return 1;
            }
        }
       
        return 0;
    }

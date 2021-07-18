vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        vector<int>v;
        int i;
        priority_queue<int,vector<int>,greater<int>>q;
        
            for(i=0;i<num;i++)
            {
                q.push(arr[i]);
                if(q.size()>K)
                {
                    v.push_back(q.top());
                    q.pop();
                }
            }
            while(!q.empty())
            {
                 v.push_back(q.top());
                    q.pop();
            }
            return v;
        
        
        
        
        
    }
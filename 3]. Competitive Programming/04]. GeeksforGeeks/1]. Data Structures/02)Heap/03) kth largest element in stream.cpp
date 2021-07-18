vector<int> kthLargest(int k, int arr[], int n) {
        // code here
         int i;
         vector<int>res,v;
        priority_queue<int,vector<int>,greater<int>>q;
        if(k==1)
        {
            for(i=0;i<n;i++)
            {
            v.push_back(arr[i]);
            }
            return v;
        }

        for(i=0;i<n;i++)
        {
            if(q.size()<k)
            {
            q.push(arr[i]);
            
            }
            else
            {
            if(q.top()<arr[i])
            {
               
                 q.pop();
                q.push(arr[i]);
               
            }
            }
            if(q.size()<k)
            {
                 v.push_back(-1);
            }
            else
            {
                 v.push_back(q.top());
            }
        }
       return v;
    }
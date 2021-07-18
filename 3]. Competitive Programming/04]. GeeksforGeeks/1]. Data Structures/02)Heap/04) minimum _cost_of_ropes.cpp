long long minCost(long long arr[], long long n) {
        // Your code here
         priority_queue<long long,vector<long long>,greater<long long>> q;
        long long i;
        for(i=0;i<n;i++)
        {
            q.push(arr[i]);
        }
    
      long long sum=0;
        
       
        while(q.size()>=2)
        {
           long long x=0;
        for(i=0;i<2;i++)
        {
        
            x=x+q.top();
            q.pop();
       
        }
        q.push(x);
        sum=sum+x;
        }
        return sum;
        
        
    }
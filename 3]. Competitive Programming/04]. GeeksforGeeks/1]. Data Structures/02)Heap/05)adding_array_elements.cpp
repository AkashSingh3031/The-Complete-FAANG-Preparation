int minOperations(int arr[], int n, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> q;
        int i;
        for(i=0;i<n;i++)
        {
            q.push(arr[i]);
        }
      int count=0;
      int sum;
        if(q.top()<0)
        {
            return 0;
        }
         int x=0;
        while(!q.empty())
        {
            sum=0;
           
        for(i=0;i<2;i++)
        {
        if(q.top()<k)
        {
            sum=sum+q.top();
            x++;
            q.pop();
            
           
        }
        else if(q.top()>=k)
        {
                return x-count;
        }
        }
        q.push(sum);
        count++;
        }
       
        return count;
    }
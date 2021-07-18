 vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>v;
        int i,j;
        priority_queue<int,vector<int>,greater<int>>q;
        for(i=0;i<K;i++)
        {
            for(j=0;j<K;j++)
            {
                q.push(arr[i][j]);
            }
        }
        while(!q.empty())
        {
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
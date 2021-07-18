 vector<int> topK(vector<int>& nums, int k) {
        // Code here
        
        vector<int>v;
        int count=0;
        int mx;
        int res;
        map<int,int>m;
        int i;
        for(i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto i=m.begin();i!=m.end();i++)
        {
            q.push({i->second,i->first});
        }
        while(k)
        {
            v.push_back(q.top().second);
            q.pop();
            
           k--;
            
        }
      
       
        return v;
    }
 vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        int i=0;
        int j=0;
        list<int>q;
        vector<int>v;
        int mx=INT_MIN;
        while(j<n)
        {
            
          while(q.size()>0 && q.back()<arr[j])
          {
              q.pop_back();
          }
          q.push_back(arr[j]);
            if(j-i+1==k)
            {
               v.push_back(q.front());
               if(q.front()==arr[i])
               {
                   q.pop_front();
               }
               i++;
               j++;
            }
           else if(j-i+1<k)
            {
                j++;
            }
           
        }
       
        
     return v;   
        
    }
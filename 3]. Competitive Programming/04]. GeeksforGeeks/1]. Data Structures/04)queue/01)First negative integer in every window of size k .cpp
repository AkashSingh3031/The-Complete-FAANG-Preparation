vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                                                 
        vector<long long>v;
        queue<long long>q;
        long long i=0;
        long long j=0;
        while(j<N)
        {
            if(A[j]<0)
            {
               q.push(A[j]); 
            }
            if(j-i+1<K)
            {
           
             j++;
            
            }
            else if(j-i+1==K)
            {
                if(!q.empty())
                {
               v.push_back(q.front());
               if(q.front()==A[i])
               {
                   q.pop();
               }
                }
                else
                {
                    v.push_back(0);
                }
               i++;
                j++;
                
            }
           
            
        }
             return v;                                    
                                                 
                                                 
                                                 
                                                 
 }
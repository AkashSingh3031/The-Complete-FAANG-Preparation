vector<long long> findMissing(long long A[], long long B[],  
                 int N, int M) 
	{ 
	    // Your code goes here
	    vector<long long>v;
	    int i;
	   map<int,int>m;
	    for(i=0;i<M;i++)
	    {
	      m[B[i]]++;
	    }
	    for(i=0;i<N;i++)
	    {
	      
	         if(m[A[i]]==0)
	         {
	              v.push_back(A[i]);
	         }
	       
	    }
	  
	    return v;
	    
	} 

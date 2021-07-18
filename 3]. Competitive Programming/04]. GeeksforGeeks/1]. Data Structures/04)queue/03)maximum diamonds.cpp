int maxDiamonds(int A[], int N, int K) {
        // code here
      int count=0;
      int i;
      int sum=0;
      priority_queue<int>q;
     
      
      
      for(i=0;i<N;i++)
      {
          q.push(A[i]);
      }
      
     while(K)
     {
         int x=q.top();
         sum=sum+q.top();
         q.pop();
         q.push(x/2);
         K--;
         
     }    
         
     
                return sum;
    
        
        
        
        
        
        
        
    }
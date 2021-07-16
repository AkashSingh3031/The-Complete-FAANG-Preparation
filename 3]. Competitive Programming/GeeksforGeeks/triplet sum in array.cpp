int countTriplets(int A[], int N, int L, int R) {
        // code here
       
        int i,j,k;
        int sum,count=0;
        sort(A,A+N);
        for(i=0;i<N-2;i++)
        {
                j=i+1;
                k=N-1;
                while(j!=k)
                {
            
                    sum=A[i]+A[j]+A[k];
                    
                    
                 if(sum>R)
                  {  
                     k--;
                  }
                  else if(sum>=L)
                  {
                      
                      count1++;
                     
                      j++;
                       
                    
                  }
                  else
                  {
                      j++;
                  }
                    
                }
            
        }
           
        
    
    return count;
    }

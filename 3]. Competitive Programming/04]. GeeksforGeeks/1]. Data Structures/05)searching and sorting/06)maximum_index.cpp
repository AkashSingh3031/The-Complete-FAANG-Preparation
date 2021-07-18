 int maxIndexDiff(int arr[], int n) 
    { 
        
        // Your code here'
       
        int mx=INT_MIN;
        int L[n];
        int R[n];
        L[0]=arr[0];;
        R[n-1]=arr[n-1];
        int i,j;
        for(i=1;i<n;i++)
        {
            L[i]=min(arr[i],L[i-1]);
        }
        for(j=n-2;j>=0;j--)
        {
            R[j]=max(arr[j],R[j+1]);
        }
        i=0,j=0;
        while(i<n && j<n)
        {
             if(arr[i]<=R[j])
            {
                mx=max(mx,j-i);
                j++;
            }
            else
            {
           i++;
            }
        }
      
        return mx;
    }
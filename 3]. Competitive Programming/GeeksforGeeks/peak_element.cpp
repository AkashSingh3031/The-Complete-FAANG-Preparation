int peakElement(int arr[], int n)
    {
       // Your code here
       int l=0;
       int h=n-1;
       while(l<=h)
       {
           int mid=l+(h-l)/2;
           
           if((mid==0|| arr[mid]>=arr[mid-1] )&&(mid==n-1||arr[mid]>=arr[mid+1]))
           {
               return mid;
           }
           else if(mid>0 && arr[mid]<=arr[mid-1])
           {
               h=mid-1;
           }
           else
           {
               l=mid+1;
           }
       }
       return 0;
       
       
    }

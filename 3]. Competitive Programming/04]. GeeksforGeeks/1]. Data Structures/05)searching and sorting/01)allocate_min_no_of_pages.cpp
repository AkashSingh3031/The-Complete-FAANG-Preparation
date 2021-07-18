bool isvalid(int arr[],int n,int x,int k)
    {
        int i;
        int student=1;
        int sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(sum>x)
            {
                student++;
                sum=arr[i];
            }
            if(student>k)
        {
            return false;
        }
        }
        
        
        return true;
        
    }
    
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int i;
        int mx=INT_MIN;
        int sum=0;
        int res=-1;
        if(m>n)
        {
            return res;
        }
        for(i=0;i<n;i++)
        {
            mx=max(mx,arr[i]);
            sum=sum+arr[i];
        }
        int start=mx;
        int end=sum;
    
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isvalid(arr,n,mid,m))
            {
                res=mid;
                end=mid-1;
            }
            else
            {
              start=mid+1;
            }
        }
        return res;
        
    }
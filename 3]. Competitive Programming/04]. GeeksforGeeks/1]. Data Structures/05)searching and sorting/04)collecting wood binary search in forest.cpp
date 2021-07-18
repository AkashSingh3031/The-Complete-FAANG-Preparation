int find_height(int tree[], int n, int k)
    {
        // code here
        sort(tree,tree+n);
        int left=0;
        int right=tree[n-1];
       
       
        int i,mid=0;
        while(left<=right)
        {
             mid=left+((right-left)/2);
              int sum=0;
        for(i=n-1;i>=0;i--)
        {
            
              if(tree[i]<mid)
              {
                  break;
              }
              
            sum=sum+(tree[i]-mid);
        }
        if(sum==k)
        {
            return mid;
        }
        else if(sum>k)
        {
            left=mid+1;
        }
        else if(sum<k)
        {
            right=mid-1;
        }
        }
        return -1;
    }
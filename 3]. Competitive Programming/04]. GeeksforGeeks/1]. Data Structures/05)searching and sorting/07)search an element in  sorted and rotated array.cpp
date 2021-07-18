
int Search(vector<int> vec, int K) {
    //code here
    
    int res,mid;
    int l,h,result;
    int i;
    int n=vec.size();
   l=0;
   h=n-1;
   while(l<=h)
   {
      res=l+(h-l)/2;
      
      if(vec[res]<=vec[(res+1)%n] && vec[res]<=vec[(res+n-1)%n])
      {
          result=res;
          break;
      }
      else if(vec[res]>vec[n-1])
      {
          l=res+1;
      }
     else if(vec[res]<vec[n-1])
      {
          h=res-1;
      }
      
      
   }
    l=0;
    h=result-1;
   while(l<=h)
    {
        
        mid=l+(h-l)/2;
        if(vec[mid]==K)
        {
            return mid;
        }
        else if(vec[mid]<K)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    l=result;
    h=n-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(vec[mid]==K)
        {
            return mid;
        }
        else if(vec[mid]<K)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
   
    return -1;
    
}
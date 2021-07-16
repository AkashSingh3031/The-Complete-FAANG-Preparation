int Search(vector<int> vec, int K) {
    //code here
    
    int res;
    int l,h;
    int i;
    int mn=INT_MAX;
    for(i=0;i<vec.size();i++)
    {
        if(vec[i]<mn)
        {
            mn=vec[i];
            res=i;
        }
    }
    l=0;
    h=res-1;
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
    l=res;
    h=vec.size()-1;
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

long long int floorSqrt(long long int x) 
    {
        // Your code goes here  
       
    int i,l,h,mid;
   
    l=1;
    h=x;
    long  long res;
    if(x==0||x==1)
    {
        return x;
    }
    while(l<=h)
    {
         mid=l+(h-l)/2;
        if(mid*mid==x)
        {
            return mid;
        }
        if(mid<=x/mid)
        {
            
            res=mid;
            l=mid+1;
        }
       
        else 
        {
            h=mid-1;
        }
        
    }
    return res;
    }
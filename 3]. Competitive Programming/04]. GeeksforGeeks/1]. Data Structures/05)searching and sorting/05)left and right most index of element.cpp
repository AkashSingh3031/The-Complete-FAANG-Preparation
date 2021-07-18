pair<long,long> indexes(vector<long long> a, long long x)
    {
        // code here
        int left=0;
        int high=a.size()-1;
        long long  firstoc=-1,last=-1;
        long long mid;
        pair<int,int>p;
        while(left<=high)
        {
            mid=left+(high-left)/2;
            if(a[mid]==x)
            {
                firstoc=mid;
                high=mid-1;
                
            }
            else if(a[mid]>x)
            {
                high=mid-1;
            }
            else if(a[mid]<x)
            {
                left=mid+1;
            }
        }
        left=0;
        high=a.size()-1;
        while(left<=high)
        {
            mid=left+(high-left)/2;
            if(a[mid]==x)
            {
                last=mid;
                left=mid+1;
                
            }
            else if(a[mid]>x)
            {
                high=mid-1;
            }
            else if(a[mid]<x)
            {
                left=mid+1;
            }
        }
        
        p.first=firstoc;
        p.second=last;
        
        return p;
        
    }
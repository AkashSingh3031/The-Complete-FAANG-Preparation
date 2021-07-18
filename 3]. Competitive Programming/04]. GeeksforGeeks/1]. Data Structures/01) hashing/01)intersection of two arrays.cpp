int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
        // Your code goes here
        map<int,int>m;
        int j=0;
        int i=n;
        for(j=0;j<m;j++)
        {
           a[i++]=b[j];
        }
        for(i=0;i<n+m;i++)
        {
            m[a[i]]++;
            
        }
        for(i=0;i<n+m;i++)
        {
            if(m[arr[i]]>=1)
            {
                count++;
            }
        }
        map<int,int>ms;
        map<int,int>mp;
        int count=0;
        int i;
        for(i=0;i<n;i++)
        {
            ms[a[i]]++;
        }
        for(i=0;i<m;i++)
        {
            mp[b[i]]++;
        }
        if(n>m)
        {
        for(i=0;i<n;i++)
        {
            if(mp[a[i]]>=1)
            {
                count++;
                mp[a[i]]=0;
                mp[a[i]]=0;
            }
        }
        }
        else
        {
             for(i=0;i<m;i++)
        {
            if(ms[b[i]]>=1)
            {
                count++;
                ms[b[i]]=0;
                ms[b[i]]=0;
            }
        }
            
        }
        return count;
    }
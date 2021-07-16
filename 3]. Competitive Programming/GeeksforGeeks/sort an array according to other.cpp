 int binary(int l, int h, vector<int>A1,int x)
    {
        int mid;
         while(l<=h)
    {
         mid=l+(h-l)/2;
        if((A1[mid]==x) &&(mid==0 ||A1[mid-1]<x))
        {
            
           return mid;
              
           
            
        }
        else if(A1[mid]>x)
        {
            
           h=mid-1;
        }
       else if(A1[mid]<x)
       {
           l=mid+1;
       }
        
        
    }
    }
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code here
        vector<int>v;
        int i,l,j,h,mid,res,ress;
        bool present[N];
        sort(A1.begin(),A1.end());
        for(i=0;i<M;i++)
        {
           int res= binary(0,N-1,A1,A2[i]);
       
    for(j=res;(j<N && A1[j]==A2[i]);j++)
        {
                 v.push_back(A1[j]);
                 present[j]=true;
                
        }
    
        }
      
        for(i=0;i<N;i++)
        {
            if(present[i]!=true)
            {
                v.push_back(A1[i]);
            }
        }
        return v;
        
    } 

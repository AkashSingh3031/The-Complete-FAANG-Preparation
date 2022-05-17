#include<bits/stdc++.h> 
using namespace std; 

class Solution
{   
  public:
    int rightmostNonZeroDigit(int n, int a[])
    {
        // code here 
        int count = 0;
        for (int i = 0; i < n; i++) 
        {
            while (a[i] > 0 && a[i] % 5 == 0)
            {
                a[i] /= 5;
                count++;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            while (count && a[i] > 0 && !(a[i] & 1)) 
            {
                a[i] >>= 1;
                count--;
            }
        }
        
        long long ans = 1;
        for (int i = 0; i < n; i++) 
            ans = (ans * a[i] % 10) % 10;
        
        if (count)
            ans = (ans * 5) % 10;
     
        if (ans)
            return ans;
     
        return -1;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;++i)
            cin>>A[i];
        
        Solution ob;
        cout << ob.rightmostNonZeroDigit(n, A) << endl;
    }
    return 0; 
}

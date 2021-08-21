#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
  public:
    int trailingZeroes(int n)
    {
        // Write Your Code here
        if(n < 0)
            return -1;
        int count = 0;
        for(int i=5; floor(n/i)>=1; i*=5)
            count += floor(n/i);
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}

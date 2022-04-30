/*
For a given N, find the number of ways to choose an integer x from the range [0,2N−1] such that x⊕(x+1)=(x+2)⊕(x+3), where ⊕ denotes the bitwise XOR operator.
Since the number of valid x can be large, output it modulo 109+7.
Sample Input
2
1
2
Sample Output
1
2
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long sol(long long x,long long y,long long p)
{
   long long res=1;
    x= x % p;
    if(x == 0){ 
    return 0;
    }
    
    while(y > 0)
    {
        if(y & 1)
            res=(res*x)%p;
        y=y>>1;
        x = (x*x)%p;
    }
    return res;
}
int main(){
    int t; 
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long ans =sol(2,n-1,mod);
        cout<<ans<<endl;
    }
    return 0;
}

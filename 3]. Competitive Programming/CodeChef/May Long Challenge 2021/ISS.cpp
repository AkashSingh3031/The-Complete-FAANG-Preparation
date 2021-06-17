/*
Zanka finds fun in everyday simple things. One fine day he got interested in a very trivial sequence. Given a natural number k, he considers the sequence Ai=k+i2 
so that the terms are k+1,k+4,k+9,k+16,…
Now to make things more interesting, he considers the gcd of consecutive terms in the sequence, then takes the sum of the first 2k values. More formally, he wants to compute
∑i=12kgcd(Ai,Ai+1)
Denote this sum by S. Zanka wants you to print the number S for each k.
Input
The first line contains an integer T, the number of test cases. Descriptions of test cases follow.
The only line of each test case contains a single integer k.
Output
For each test case, output a single line containing the sum S for the given k.
Sample Input
1
1
Sample output
6
*/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N = 4e6+5;
    int phi[N] , ans[N];
    for(int  i = 0 ; i < N ; i++){
        phi[i] = i;
        ans[i] = 0;
        }
    
    for(int p = 2 ; p < N ; p++){
        if(phi[p]==p){
            phi[p] = p-1;
        for(int i = 2*p ; i<N ;i+=p)
            phi[i] = (phi[i]/p)*(p-1);
        }
    }
    for(int  i = 1 ; i < N ; i++){
        ans[i] +=i-1;
        for(int j = 2*i ; j<N ; j+=i){
          ans[j]+=i*((1 + phi[j/i])/2);
        }  
    }    
    ll t;
    cin>>t;
    while(t--)
    {
        ll k;
        cin>>k;
        cout<<ans[4*k+1]<<"\n";
    }
    
    return 0;
}

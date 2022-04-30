/*
    
    
    Solution By : Rahul Surana
    
    ***************************************************************************

Here is another task for you, prepared by Monk himself. So, this is how it goes :

Given an integer array A of size N, Monk needs you to answer T queries for him. In each query, he gives you 2 integers P and Q. In response to each of these queries, you need to tell Monk the count of numbers in array A. that are either divisible by P, Q, or both.

Can you cope with this ?

Input Format :

The first line contains a single integer N denoting the size of array A. The next line contains N space separated integers, where the ith integer denotes A[i].

The next line contains a single integer T denoting the number of queries Monk poses to you. Each of the next T lines contains 2 space separated integers P and Q.

Output Format :

For each query, print the answer on a new line.


    ***************************************************************************

*/



#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define FOR(i,a)     for(int i = 0; i < a; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000007 
using namespace std;

vector<int> ar;

vector<int> ans(200001,0);

int gcd(int K, int M) {
      int k = max(K,M);
      int m = min(K,M);
      // loop invariant: k ≥ m ∧ GCD(K,M) = GCD(k,m)
      while (m != 0) {
         int r = k % m;
         k = m;
         m = r;
      }
      // At this point, GCD(K,M) = GCD(k,m) = GCD(k,0) = k
      return k;
   }

int expo(int x, int y) {
    int o = 1;
    while(y>0) {
        if(y&1) o*=x;
        x*=x;
        y = y >> 1; 
    }
    return o;
}

void prime_fact(int a) {
    vector<int> mk;
    for(int i = 2; i*i <= a; i++){
        if(a % i == 0 && a != 0){
            int c = 0;
            while(a % i == 0 && a != 0) { 
                c++; 
                a/=i; 
                mk.pb(expo(i,c)); 
            }
        }
    }
    if(a>1) mk.pb(a);
    for(int i = 0; i < mk.size();i++) {
        for(int j = i; j < mk.size();j++){
            if(i==j) ans[mk[i]]++;
            else{
                if(mk[j]%mk[i] != 0 && mk[j]*mk[i] < 200001) {
                    // cout <<"mkji" <<mk[j] << " " << mk[i] <<" "<<mk[i]*mk[j] << "\n";
                    ans[mk[j]*mk[i]]++; }
            }
        }
    }
    // FOR(i,mk.size())  cout << mk[i]<<" ";
    // cout << "\n";
}

int main()
{
    fast_io;
    int n;
    cin >> n;
    FOR(i,n) { int a; cin >> a; ar.pb(a); }
    FOR(i,n) prime_fact(ar[i]);
    ans[1] = ar.size();
    // cout << ans[36877] <<" " << ans[51283] << "\n";
    // cout << 36877*51283/gcd(36877,51283) <<" ";
    // if(i<100 && ar[i]%3 == 0) cout << ar[i] <<" " <<ans[2] << " " << ans[3]<<" "<< ans[6]<<"\n"; }
   
    int t;
    cin >> t;
    while(t--){
        ll p,q;
        cin >> p >> q;
        ll x = ((p*q)/gcd(p,q));
        if(p == q) cout<<ans[p]<<"\n";
        else if( x <= 200000) { 
        // cout << p*q/gcd(p,q)<<" " << ans[p*q/gcd(p,q)] <<" ";
        cout << ans[p] + ans[q] - ans[x] << "\n";}
        else cout << ans[p] + ans[q] << "\n";
    }

    // if(mk[0] == 2) cout <<ans[2] << " " << ans[3]<<"\n";
    // if(s == 6) { FOR(i,mk.size())  cout << mk[i]<<" ";}
    // if(s==6) cout << "\n";
}


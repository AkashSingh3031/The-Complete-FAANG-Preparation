#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll MOD = 1e9+7;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> vec;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            if(i==n/i){
                vec.pb(i);
            }
            else{
                vec.pb(i);
                vec.pb(n/i);
            }
        }
    }
    ll one=0,zero=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='1') one++;
        else if(s[i]=='0') zero++;
    }
    if(one==0){
        cout << 1 << "\n";
        return;
    }
    ll ans = min(one-1,zero);
    ll m = vec.size();
    for(ll i=0;i<m;i++){
        ll po = vec[i];
        for(ll l=0;l<po;l++){
            ll one1=0,zero1=0;
            ll ans1=0;
            for(ll k=l;k<n;k+=po){
                if(s[k]=='1') one1++;
                else zero1++;
            }
            ans1=one-one1+zero1;
            ans=min(ans,ans1);
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
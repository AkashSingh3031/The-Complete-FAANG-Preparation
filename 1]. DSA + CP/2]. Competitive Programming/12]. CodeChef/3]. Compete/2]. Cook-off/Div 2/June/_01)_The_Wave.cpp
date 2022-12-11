#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9+7;

void solve(){
    ll n,q; cin >> n >> q;
    vector<ll> vec(n);
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        cin >> vec[i];
        mp[vec[i]]++;
    }
    sort(vec.begin(),vec.end());
    while(q--){
        ll x; cin >> x;
        if(mp[x]>0){
            cout << 0 << "\n";
            continue;
        }
        ll t = lower_bound(vec.begin(),vec.end(),x)-vec.begin();
        ll index = n-t;
        if(t%2==0){
            cout << "POSITIVE" << "\n";
        }
        else{
            cout << "NEGATIVE" << "\n";
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
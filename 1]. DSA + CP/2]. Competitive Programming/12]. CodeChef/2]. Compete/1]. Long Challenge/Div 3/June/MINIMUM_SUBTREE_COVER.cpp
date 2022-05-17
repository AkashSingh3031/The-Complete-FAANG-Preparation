#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
 
int getFar(int node, vvi & G, int n){
  vector<bool> done(n+1, false);
  int fd=-1, far;  done[node] = true;
  queue<pair<int, int>> qu; qu.push({node, 0});
  while(qu.size()){
    auto pi = qu.front(); qu.pop();
    int nod = pi.first, dis = pi.second;
    if(fd < dis) fd = dis, far = nod;
    for(auto cnod: G[nod]){
      if(done[cnod]) continue;
      done[cnod] = true;
      qu.push({cnod, dis+1});
    }
  }
  return far;
}
 
void dfs(int nod, int par, vvi & G, vi & H, vi & li, int cur){
  bool isleaf = true;
  int mx = 0;
  for(auto cnod: G[nod]) if(cnod != par) {isleaf = false; mx = max(mx, H[cnod]);}
  if(isleaf){ li.push_back(cur); return; }
 
  int c = 0;
  for(auto cnod: G[nod]){
    if(cnod == par) continue;
    if(H[cnod] == mx && c==0){
      dfs(cnod, nod, G, H, li, cur+1); c++;
    }
    else dfs(cnod, nod, G, H, li, 1);
  }
}
 
void fixHeight(int nod, int par, vvi & G, vi & H){
  bool isleaf = true;
  for(auto cnod: G[nod]){
    if(cnod == par) continue;
    isleaf = false;
    fixHeight(cnod, nod, G, H);
    H[nod] = max(H[nod], 1 + H[cnod]);
  }
  if(isleaf) H[nod] = 1;
}
 
void breakIntoLines(int nod, int par, vvi & G, vi&li, int n){
  vector<int> H(n+1, 0);
  fixHeight(nod, par, G, H);
  dfs(nod, par, G, H, li, 1);
}
 
int getSol(vvi & gr, int n, int k){
  if(k==1) return 1;
  int u = getFar(1, gr, n);
  vector<int> li;
  breakIntoLines(u, 0, gr, li, n);
  sort(li.rbegin(), li.rend());
  int size = 1, total = 0, i = 0;
  while(total < k){
    size++; total += li[i++];
  }
  return size;
}
 
void solve(){
     int n, k;
     int u, v;
 
    cin>>n>>k;
    vvi gr(n+1);
    for(int i=1; i<n; i++){
      cin>>u>>v;
      gr[u].push_back(v); gr[v].push_back(u);
    }
    cout << getSol(gr, n, k) << "\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int t;
    cin>>t;
    // t = 1;
    int _=1;
    while(t--){
        // cout<<"Case #"<<_++<<": ";
        solve();
    }
    return 0;
}
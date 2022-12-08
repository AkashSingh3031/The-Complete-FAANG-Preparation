#include<algorithm>
int findPar(int u,vector<int> &par){
    if(u == par[u]){
        return u;
    }
    return par[u] = findPar(par[u],par);
}
    
int union_(int u, int v, vector<int> &rank,vector<int> &par){
    if(rank[u]<rank[v]){
        par[u] = v;
    }else if(rank[v]<rank[u]){
        par[v] = u;
    }else{
        par[v] = u;
        rank[u]++;
    }
}
    
bool comp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    // Write your code here.
    sort(graph.begin(),graph.end(),comp);
    int cost = 0;
    vector<int> par(n+1),rank(n+1,0);
    for(int i=1;i<par.size();++i) par[i] = i;
    
    for(auto i:graph){
        if(findPar(i[0],par)!=findPar(i[1],par)){
            cost+=i[2];
            union_(findPar(i[0],par),findPar(i[1],par),rank,par);
        }
    }
    
    return cost;
    
}
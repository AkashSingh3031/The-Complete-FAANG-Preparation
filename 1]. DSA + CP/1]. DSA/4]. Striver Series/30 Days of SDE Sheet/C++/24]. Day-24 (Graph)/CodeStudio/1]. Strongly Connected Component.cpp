#include<bits/stdc++.h>
void dfs(int s, vector<int> &vis,vector<int> adj[], stack<int> &st){
   vis[s]=1;
   for(auto it : adj[s]){
       if(!vis[it])
           dfs(it,vis,adj,st);
   }
   st.push(s);
}
void revdfs(int s,vector<int> &vis,vector<int> tra[],vector<int> &res){
   vis[s]=1;
   res.push_back(s);
   for(auto it:tra[s]){
       if(!vis[it]){
           revdfs(it, vis, tra,res);
       }
   }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
   // Write your code here.
   vector<vector<int>> ans;
   vector<int> vis(n,0);
   vector<int> adj[n];
   vector<int> tra[n];
   stack<int> st;
   for(auto it:edges){
       adj[it[0]].push_back(it[1]);
   }
   for(int i=0;i<n;i++){
       if(!vis[i]){
           dfs(i,vis,adj,st);
       }
   }
   for(int i=0;i<n;i++){
       vis[i]=0;
       for(auto it: adj[i]){
           tra[it].push_back(i);
       }
   }
   while(!st.empty()){
       int a=st.top();
       st.pop();
       if(!vis[a]){
           vector<int> res;
           revdfs(a,vis,tra,res);
           ans.push_back(res);
       }
   }
   return ans;
}
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> wt(V,INT_MAX);
        vector<int> mst(V,0);
        vector<int> par(V,-1);
        wt[0]=0;
        par[0]=-1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int node=pq.top().second;
            mst[node]=1;
            pq.pop();
            for(auto it:adj[node]){
            int v=it[0];
            int weight=it[1];
            if(mst[v]!=1&&wt[v]>weight){
                wt[v]=weight;
                pq.push({wt[v],v});
                par[v]=node;
            }
            }
        }
        int sum=0;
        for(int i=0;i<V;i++){
            sum+=wt[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
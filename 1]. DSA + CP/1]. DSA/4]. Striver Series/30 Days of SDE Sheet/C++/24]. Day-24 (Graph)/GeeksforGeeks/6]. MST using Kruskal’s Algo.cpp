//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findpar(int node,vector<int>&parent)
	{
	    if(node==parent[node])
	        return node;
	    return parent[node]=findpar(parent[node],parent); 
	}
	
	void Union(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        u=findpar(u,parent);
        v=findpar(v,parent);
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[v]<rank[u])
            parent[v]=u;
        else
        {
            parent[v]=u;
            rank[u]++;
        }
    }
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        multimap<pair<int,int>,int>mp; //sort by weight
       
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                mp.insert({{it[1],i},it[0]});
            }
        }
        vector<int>parent(V,0);
        vector<int>rank(V,0);
        
        for(int i=0;i<V;i++)
            parent[i]=i;
        
        int ans=0;
        
        for(auto it:mp)
        {
            if(findpar(it.first.second,parent)!=findpar(it.second,parent))
            {
                ans+=it.first.first;
                Union(it.first.second,it.second,parent,rank);
            }
        }
        return ans;
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
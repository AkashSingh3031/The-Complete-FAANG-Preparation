#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	class Edge{
        public:
        int distance;
        int vertex;
        Edge(int d, int v){
            distance=d;
            vertex=v;
        }
    };
    
    class Comparator{
        public:
            bool operator()(const Edge& e1, const Edge& e2){
                return e1.distance>e2.distance;
            }
    };
    
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, INT_MAX);
        priority_queue<Edge, vector<Edge>, Comparator> pq;
        dist[S]=0;
        pq.push(Edge(dist[S], S));
        while(!pq.empty()){
            Edge e=pq.top();
            pq.pop();
            for(auto edge : adj[e.vertex]){
                int adjNodeDist=edge[1], adjNodeVertex=edge[0];
                int newDistance=e.distance+adjNodeDist;
                if(newDistance<dist[adjNodeVertex]){
                    dist[adjNodeVertex]=newDistance;
                    pq.push(Edge(dist[adjNodeVertex], adjNodeVertex));
                }
            }
        }
        return dist;
    }
};


// { Driver Code Starts.


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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
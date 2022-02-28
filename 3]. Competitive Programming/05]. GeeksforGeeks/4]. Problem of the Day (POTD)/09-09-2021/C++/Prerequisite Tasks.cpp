#include<bits/stdc++.h>
using namespace std;

class Solution 
{
  public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
	{
	    // Code here
	    vector<vector<int>> graph(N);
        vector<bool> vis(N, false);
        vector<bool> st(N, false);
        
        for(auto p : prerequisites)
            graph[p.first].push_back(p.second);
        
        for(int i=0; i<N; i++)
        {
            if(!vis[i])
            {
                if(isCycle(graph, vis, i, st))
                return false;
            }
        }
        return true;
	}
	
	bool isCycle(vector<vector<int>> &graph, vector<bool> &vis, int u, vector<bool> &st)
    {
        if(vis[u])
            return false;
        
        st[u] = true;
        vis[u] = true;
        
        for(auto it : graph[u])
        {
            
            if(st[it] || isCycle(graph, vis, it, st))
            return true;
        }
        st[u] = false;
        return false;
    }
};

int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
    	int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}

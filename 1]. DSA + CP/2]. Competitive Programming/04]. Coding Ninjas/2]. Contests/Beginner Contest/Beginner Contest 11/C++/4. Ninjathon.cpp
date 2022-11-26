/*
    Time Complexity : O( N )
    Space Complexity : O( N ) 
    
    where 'N' is the total number of cities. 
*/

int longestTrack(int n, vector < vector < int > > edges) {
   // If total city are '1', return '1'.
   if(n == 1) {
      return 1;
   }
   // Creating a adjacency list out of edges.
   vector < int > graph[n];
   for (int i = 0; i < edges.size(); i++) {
      // Creating a undirected graph.
      graph[edges[i][0]].push_back(edges[i][1]);
      graph[edges[i][1]].push_back(edges[i][0]);
   }

   // 'ANS' stores the longest path with most cities.
   int ans = 1;
   int farthest = 0;
   queue < int > bfs;

   // Distance array as 'DIS'.
   vector < int > dis(n, 0);
   dis[0] = 1;
   bfs.push(0);
   while (bfs.size()) {
      int u = bfs.front();
      bfs.pop();
      for (int v: graph[u]) {
         if (dis[v])
            continue;
         dis[v] = dis[u] + 1;
         bfs.push(v);
         // Storing the farthest node from '1'.
         if (ans < dis[v]) {
            ans = dis[v];
            farthest = v;
         }
      }
   }

   fill(dis.begin(), dis.end(), 0);
   dis[farthest] = 1;
   bfs.push(farthest);
   while (bfs.size()) {
      int u = bfs.front();
      bfs.pop();
      for (int v: graph[u]) {
         if (dis[v])
            continue;
         dis[v] = dis[u] + 1;
         bfs.push(v);
         // Storing the farthest node from '1'.
         ans = max(ans, dis[v]);
      }
   }
   return ans;
}
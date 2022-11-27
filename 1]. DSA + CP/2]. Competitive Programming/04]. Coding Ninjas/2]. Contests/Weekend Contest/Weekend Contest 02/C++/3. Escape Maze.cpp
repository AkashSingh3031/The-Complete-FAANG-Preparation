/*
   Time Complexity: O(n*m)
   Space Complexity: O(n*m)

   Where n and m are the dimensions of the matrix. arr.
*/

#include <deque>

bool escape(int n, int m, vector<vector<char>> maze, int k)
{
    deque<vector<int>> pq;
    
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    dist[0][0] = 0;
    visited[0][0] = false;

    //-ve sign is used to make a non-decreasing queue.
    pq.push_back({-dist[0][0], 0, 0});

    while(!pq.empty())
    {
        // Pop out the first vertex in the deque.
        vector<int> cell = pq.front();
        pq.pop_front();
        int x = cell[1];
        int y = cell[2];
        if (visited[x][y] == true)
        {
            continue;
        }
        
        if (maze[x][y] == 'D')
        {
            if (dist[x][y] <= k)
            {
                return true;
            }
        }

        if (dist[x][y] > k)
        {
            return false;
        }
        
        visited[x][y] = true;

        // Add the neighbours of the current cell if they are not visited already.
        vector<vector<int>> neighbours = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        for (auto &neigh : neighbours)
        {
            int i = x + neigh[0];
            int j = y + neigh[1];
            if (i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == false)
            {
                // If the cell is empty or has a door, the path has a weight of 0.
                if (maze[i][j] == '.' || maze[i][j] == 'D')
                {
                    dist[i][j] = min(dist[i][j], dist[x][y]);
                    pq.push_front({-dist[i][j], i, j});
                }

                // If the cell is a wall, the path has a weight of 1.
                else
                {
                    dist[i][j] = min(dist[i][j], dist[x][y] + 1);
                    pq.push_back({-dist[i][j], i, j});
                }
            }
        }
    }
    
    return false;
}

/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(N)

    where 'N' is the number of points provided.
*/

#include<set>

int find(int n, vector< vector<int>> &points){

    // Storing the set of points
    set<vector<int>> s;

    for(int i  = 0; i < n; i++){
        s.insert(points[i]);
    }
    int count = 0;

    // Fixing the top-left and bottom-right corner of the rectangles.
    for(int i = 0; i < n; i++){
        int xi = points[i][0], yi = points[i][1];
        for(int j = 0; j < n; j++){
            int xj = points[j][0], yj = points[j][1];
            if(xi < xj and yi < yj and s.count({xi, yj}) and s.count({xj, yi})){
                count += 1;
            }
        }
            
    }
    return count;
}

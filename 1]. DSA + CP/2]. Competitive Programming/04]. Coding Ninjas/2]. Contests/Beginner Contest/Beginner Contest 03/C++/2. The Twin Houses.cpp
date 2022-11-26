/*
    Time complexity: O(N)
    Space complexity: O(N)

    where 'N' is the number of houses on one side.
*/

vector<int> findTwinHouses(vector<int> &a, vector<int> &b, int n) {
    
    // Map the colour to house number in right.
    vector<int> colorPosRight(n, 0);

    // Store the position of house on right.
    vector<int> position(n, 0);

    // Iterating through all the houses on right.
    for(int i = 0; i < n; ++i) {
        int x = b[i] - 1;
        // The House with colour 'x' is at position 'i'.
        colorPosRight[x] = i;
    }

    // Iterating through all the houses on left.
    for(int i = 0; i < n; ++i) {
        int x = a[i] - 1;
        // Storing the position of house on right with same colour as 'i-th' in left.
        position[i] = colorPosRight[x] + 1;
    }
    
    // Return the position of house on right.
    return position;
}
/*
   Time Complexity: O(N*S)
   Space Complexity: O(N*S)

   Where ‘N’ is the number of persons on the island and ‘S’ is the total seating capacity of the plane.
*/


bool escape(int n, int s, int w, vector<int> arrs, vector<int> arrw)
{
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    int total = 0;
    for (int i = 1; i < n + 1; i++)
    {
        total += arrw[i - 1];
        for (int j = 1; j < s + 1; j++)
        {
            // Calculating the dp transition states, where dp[i][j] represents 
            // the maximum weight that can be carried using i persons and j seating space
            dp[i][j] = dp[i - 1][j];
            if (j >= arrs[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arrs[i - 1]] + arrw[i - 1]);
            }
        }
    }

    for (int i = 0; i < s + 1; i++)
    {
        // If the weight left is less than eqaul to w,
        // Return True
        if (total - dp[n][i] <= w)
        {
            return true;
        }
    }
    
    return false;
}

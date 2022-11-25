/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the size of given array.
*/

int cherryBiscuit(vector<int> &a, int n, int k) {
    
    // Variable for storing 'ans'.
    int ans = 0;

    for (int i = 0; i < n; i++) {

        // Check if Ninja will like current Biscuit.
        if (a[i] > k) {
            ans++;
        }

    }

    // Return the final answer.
    return ans;
}

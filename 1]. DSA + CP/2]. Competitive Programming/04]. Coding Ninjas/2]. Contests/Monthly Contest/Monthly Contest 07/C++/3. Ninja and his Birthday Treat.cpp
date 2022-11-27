/*
    Time Complexity: O(N + M*log(M))
    Space Complexity: O(N)

    Where 'N' is the size of the array and 'M' is the number of candies.
*/

vector<int> birthdayTreat(vector < vector<int> > & child , int &m) {

    // Create an array 'count' of length 'M' and initialise it to 0.
    int count[m + 2] = {};

    int n = child.size();
    for (int i = 0; i < n; i++) {
        int l = child[i][0];
        int r = child[i][1];
        int x = child[i][2];

        // Add 'X' to position L and subtract 'X' from the 'R+1' of the 'count' array.
        count[l] += x;
        count[r + 1] -= x;
    }

    // Take the prefix sum of the 'count' array.
    for (int i = 1; i <= m; i++) {
        count[i] += count[i - 1];
    }

    // Create an array 'arr' to sort elements in order of decreasing frequency.
    vector<pair<int, int>>arr;
    for (int i = 1; i <= m; i++) {
        arr.push_back({count[i], i});
    }

    // Sorting in decreasing order of frequency and lexicographically minimum.
    auto cmp = [] (pair<int, int> const & a, pair<int, int> const & b) -> bool
    {
        if (a.first == b.first)return a.second < b.second;
        return a.first > b.first;
    };
    sort(arr.begin(), arr.end(), cmp);

    vector<int>ans(m);

    // Forming the permutation according to the sorted values.
    for (int i = 0; i < m; i++) {
        ans[arr[i].second - 1] = i + 1;
    }

    // Returning answer here.
    return ans;
}
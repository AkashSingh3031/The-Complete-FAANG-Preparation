/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(N)

    Where 'N' is the length of the array 'a' .
*/

int ninjaAndAuction(vector<int>&a, vector<int>&b) {

    vector<pair<int, int>>players;

    int n = a.size();

    // Storing both the rankings and sorting according to batting ranks.
    for (int i = 0; i < n; i++) {
        players.push_back({a[i], b[i]});
    }
    sort(players.begin(), players.end());

    // Storing the bowling ranks of players such that batting rank of 'ith' player is greater than '(i-1)th' player.
    vector<int>bowling;
    for (int i = 0; i < n; i++) {
        bowling.push_back(players[i].second);
    }

    // Finding the LIS in the 'bowling' array.
    vector<int>lis;
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(lis.begin(), lis.end(), bowling[i]) - lis.begin();

        if (ind == lis.size()) {
            lis.push_back(bowling[i]);
        }
        else {
            lis[ind] = bowling[i];
        }
    }

    // Length of the LIS array is our answer.
    return lis.size();
}
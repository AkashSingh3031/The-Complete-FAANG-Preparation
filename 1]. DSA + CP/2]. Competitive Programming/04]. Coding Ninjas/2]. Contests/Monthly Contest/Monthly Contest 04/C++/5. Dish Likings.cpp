/*
    Time complexity: O(N * D + D * 2 ^ D + Q * D)
    Space complexity: O(2 ^ D)

    where 'N' is the number of group members, 'D' is the number of dishes, 'Q' is the number of new persons.
*/

// Convert the dish likings to liking value.
int findVal(string &x) {
    // Store the liking value.
    int val = 0;
    
    // Iterating over all the dishes.
    for(int i = 0; i < x.size(); ++i) {
        // Multiplying liking value by 2.
        val = val << 1;
        // Adding '1' if 'i-th' dish is liked.
        val += (x[i] == '1');
    }

    // Return liking value.
    return val;
}

vector<int> countComfortableMembers(vector<string> &a, vector<string> &b, int n, int d, int q) {

    // Store the count of comfortable members for each new person.
    vector<int> ans;
    
    // Store the count of comfortable members for all possible likings.
    vector<int> cnt((1 << d), 0);

    // Iterating through all the members.
    for(auto &x : a) {
        // Conversion of dish likings to liking value.
        int val = findVal(x);
        // Increment the count of liking value.
        cnt[val]++;
    }

    // Iterating over all the dishes.
    for(int i = 0; i < d; ++i) {
        // Iterating over all possible likings of the dishes.
        for(int j = 0; j < (1 << d); ++j) {
            // Check if 'i-th' bit is set in 'j'.
            if(j & (1 << i)) {
                // Update the count of people with liking value where 'i-th' bit is off.
                cnt[j ^ (1 << i)] += cnt[j];
            }
        }
    }

    // Iterating ove all the new persons.
    for(auto &x : b) {
        // Finding the count of comfortable members.
        int c = cnt[findVal(x)];
        // Storing the count of comfortable members.
        ans.push_back(c);
    }

    // Return the count of comfortable members.
    return ans;
}
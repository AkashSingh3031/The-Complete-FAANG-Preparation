/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the size of the input array 'A'.
*/

long long minimumDistance(int n, int k, vector<int> &a) {
    // Initializing empty vectors 'neg' and 'pos'.
    vector<int> neg, pos;

    // Iterating over input array 'a' and updating 'neg' and 'pos'.
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            neg.push_back(-a[i]);
        } else {
            pos.push_back(a[i]);
        }
    }

    // Initializing variables 'add' and 'sub'.
    long long add = 0, sub = 0;

    // Iterating over vectors 'pos' and 'neg'.
    for (auto v : {pos, neg}) {
        // Sorting out the current vector.
        sort(v.rbegin(), v.rend());

        // Skip if current vector is empty.
        if (v.empty()) {
            continue;
        }

        // Update 'sub'.
        sub = max(sub, 1LL * v[0]);

        // Updating 'add'.
        for (int i = 0; i < (int)v.size(); i += k) {
            add += 2 * v[i];
        }
    }
    return (add - sub);
}

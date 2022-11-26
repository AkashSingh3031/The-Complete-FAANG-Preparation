/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(N)

    where 'N' is the size of the array.
*/

long long int dValue(vector < int > & v) {

    // Here this vector of pair will store the number of set bits and the number as pair.
    vector < pair < int, int >> a(v.size());

    for (int i = 0; i < v.size(); i++) {
        // The variable 'numberOfSetBits' will store the number of set bits in the binary reprsentation of the integer 'v[i]'. 
        int numberOfSetBits = __builtin_popcount(v[i]);
        a[i] = {
            -1 * numberOfSetBits,
            v[i]
        };
    }

    sort(a.begin(), a.end());

    // This 'ans' will store the sum of D-value.
    long long int ans = 0;

    for (int i = 0; i < a.size(); i++) {
        ans += (i + 1) * a[i].second;
    }

    return ans;
}
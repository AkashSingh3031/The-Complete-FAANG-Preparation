/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the input integer 'N'.
*/

vector<int> reArrangeIt(int n) {
    // Initializing an empty vector.
    vector<int> a(n);

    a[0] = n;
    // Updating each value.
    for (int i = 1; i < n; i++) {
        a[i] = i;
    }
    return a;
}
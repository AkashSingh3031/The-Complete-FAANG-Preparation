/*
    Time Complexity: O(log(N))
    Space Complexity: O(1)

    where 'N' is the size of the array.
*/

int side(int n) {

    // Here 'l' and 'r' represents the binary search range.
    long long l = 0, r = 100000, m;

    // Do the binary search.
    while (l < r) {
        m = (l + r) / 2;

        // If the number of gold coins is greater than the 'n' then go to right side else go to left side.
        if (m * m * m * 4 + m * m * 6 + m * 2 >= n)
            r = m;
        else
            l = m + 1;
    }
    int ans = l;

    // In the end, return the ans.
    return ans * 2;
}
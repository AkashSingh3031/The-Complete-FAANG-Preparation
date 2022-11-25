/*
    Time complexity: O(N + MAX_VALUE)
    Space complexity: O(MAX_VALUE)

    where 'N' is the size of the array and 'MAX_VALUE' is the maximum value in array 'A'.
*/

int countPairs(vector<int> &a, int n, int x, int y, int sum) {
    // Store the count of the pairs.
    int cnt = 0;

	// Finding maximum value of the array.
    int max_value = *max_element(a.begin(), a.end());

    // Frequency array to count the frequency of elements of array.
    vector<int> freq(max_value + 1, 0);

    // Loop through the first element.
    for(int i = 0; i < n; ++i) {
        // RHS Value of the equation given in approach.
        int rhs = sum - a[i] * y;

        /*
        If RHS value is not divisible by 'x' or is negative, there is no 
        pair possible for 'a[i]' as second element.
        */
        if(rhs % x || rhs <= 0) {
            // Update the frequency of 'a[i]'.
            freq[a[i]]++;
            continue;
        }

        rhs /= x;

        // Check if 'rhs' can be present in array 'a'.
        if(rhs <= max_value) {
            // Counting all the pairs possible for 'a[i]' as second element.
            cnt += freq[rhs];
        }

        // Update the frequency of 'a[i]'.
        freq[a[i]]++;
    }

    // Return the count of pairs.
    return cnt;
}

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' denotes the number of elements in the array 'ARR'.
*/


pair<int, int> countProducts(int n, vector<int> &arr) {

    /*
     * 'pos_end' and 'neg_end' stores the number of sub-arrays with positive and negative
     * products ending at index 'i' in a rolling fashion.
     * This solution uses the space optimization as mentioned in editorial.
     */
    int pos_end = 0, neg_end = 0;

    // 'pos' and 'neg' stores the total count of sub-arrays with positive and negative products.
    int pos = 0, neg = 0;

    // Iterate over the right end-point of the sub-array.
    for (int i = 0; i < n; ++i) {

        // If the current element is positive
        if (arr[i] > 0) {

            // Increment the 'pos_end' counter.
            pos_end++;
        } else {

            // If the current element is negative, then signs will change.
            // So, swap 'pos_end' and 'neg_end'.
            swap(pos_end, neg_end);

            // Also, a sub-array of size 1 containing 'arr[i]' will have negative sign.
            // So, increment 'neg_end' count.
            neg_end++;
        }

        // Add 'pos_end' and 'neg_end' values to the global counter for positive and negative product counts.
        pos += pos_end;
        neg += neg_end;
    }

    // Return the answer.
    return {pos, neg};
}
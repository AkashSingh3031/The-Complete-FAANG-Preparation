/*
    Time complexity: O(N) 
    Space complexity: O(N)

    Where 'N' is the size of the array 'A'.
*/

int LongestEquivalence(int n, int x,vector<int>& a){

    // Integer variable 'maxLength' to store answer.
    int maxLength= 1;

     // Integer variable 'l' as first pointer to point to the left end of the window.
    int l = 0;
    // Integer variable 'r' as second pointer to point to the right end of the window.
    int r = 0;

    // Calculate a prefix sum (offset by 1) to make the prefix sum array easier to use.
    vector<int> prefixSum(n+1,0);

    // Prefix sum array to calculate sum of a window quickly.
    for (int i = 1; i <= n; i++){
        prefixSum[i] = a[i - 1] + prefixSum[i - 1];
    }

   
    // Use max monotonic queue to maintain sliding window max.
    deque<int> window;

    while (l < n && r < n) {

        // Integer variable 'indexDiff' to store the length of the window.
        int indexDiff = r - l + 1;

        // Maintain monotonic characteristic by removing smaller values from queue before adding.
        while (!window.empty() && a[window.back()] <= a[r]){
            window.pop_back();
        }

        // Push the right index to the back of the deque.
        window.push_back(r);

        // Based on max of window and subarray size, calculate expected total of elements.
        long long expected = a[window.front()] * indexDiff;

        // Store actual total of values within the window in 'total' using prefix sum.
        long long total = prefixSum[r + 1] - prefixSum[l];

        // Calculate difference between expected vs actual window total.
        long long diff = expected - total;

        /* If the difference falls within the allowed limit of k, store this
        subarray length as potential answer and try extending the window size. */
        if (diff <= (long long)(x)){ 
            maxLength = max(maxLength, indexDiff);
            r++;
        } 
        else{
            // Shrinking the window from the left end.
            if (window.front() == l){
                window.pop_front();
            }

            // Shift the whole window one space forward.
            r++;
            l++;
        }
    }

    // Return 'maxLength' as the final output.
    return maxLength;
}
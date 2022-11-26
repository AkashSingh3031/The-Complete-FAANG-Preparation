/*
    Time Complexity: O(Nlog(N))
    Space Complexity: O(1)

    where 'N' is the size of the array.
*/

int kLevel(vector<int> &v, int k){
    int n = v.size();

    // Creating variable ans to store our answer.

    int ans = 1e5;
    int left = 1, right = 1e5;

    // Applying binary search to find our answer.

    while (left <= right){

        int mid = (left + right) / 2;

        // Now checking, can we clear atleast k levels if we have initailly mid coins.

        // Creating variable c to store the number of levels that we have cleared.

        int c = 0;
        int initial = mid;

        for (int i = 0; i < n; i++){
            if (initial >= v[i]){
                c++;
                initial++;
            }
        }

        if (c >= k){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    // We are returning the answer here.

    return ans;
}
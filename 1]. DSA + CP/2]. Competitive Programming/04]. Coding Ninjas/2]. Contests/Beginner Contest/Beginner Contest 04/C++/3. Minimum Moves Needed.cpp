/*
    Time complexity: O(N * Log(ARR[i]))
    Space complexity: O(N)

    Where 'N' is the size of the input array 'ARR'.
*/

#include <set>
int minimumMoves(int n, int k, vector<int> &arr) {
    // Initializing an empty set 'elements'.
    set<int> elements;

    // Looping over the array 'arr'.
    for (int i = 0; i < n; i++) {
        // While loop till current element is divisible by 'k'.
        while (arr[i] % k == 0) {
            // If current array element is not in the set then insert it.
            if (elements.find(arr[i]) == elements.end()) {
                elements.insert(arr[i]);
            }
            // Dividing the current array element by 'k'.
            arr[i] /= k;
        }
    }

    // Returning the answer: size of the set 'elements'.
    return (int)elements.size();
}

/*
    Time Complexity: O((N + M))
    Space Complexity: O(M)

    Where 'N' is the length of array ‘a’ and 'M' is the length of array ‘b’.
*/


int ninjaAndEvents(vector<int> &a, vector<int> &b) {

    // Hash Map to store the count of occurence of elements of array 'b'.
    unordered_map<int, int> occurrence;

    int n = a.size();
    int m = b.size();

    int answer = INT_MAX;
    int start = 0;
    int count = 0;

    for (int i = 0; i < m; i++) {
        occurrence[b[i]]++;

        // If the element has occured for the first time then increment 'count'.
        if (occurrence[b[i]] == 1) {
            count++;
        }
    }


    // Pointer referring to starting and end of the Window.
    int end = -1;
    for (int start = 0; start < n; start++) {

        /* While we have not reached the end of array 'a' and the valid window has not occured
           we increment the end of the Window. */
        while (end < n - 1 and count) {
            end++;

            // Decreasing 'occured[a[j]]' to mark that 'a[j]' has occured in the window.
            occurrence[a[end]]--;

            // If we don't require anymore occurence of some element, we reduce 'count'.
            if (occurrence[a[end]] == 0) {
                count--;
            }
        }

        // If the number of more elements required in the current window is '0', then it's a suitable window.
        if (count == 0) {

            // Update the answer if we have found better.
            if (answer > ( end - start + 1)) {
                answer = end - start + 1;
            }
        }

        // Sliding the starting point of the Window to the right.
        occurrence[a[start]]++;
        if (occurrence[a[start]] > 0) {
            count++;
        }
    }

    // If any sub range is possible return the 'answer', else return -1.
    if (answer != INT_MAX) {
        return answer;
    }
    else {
        return -1;
    }
}
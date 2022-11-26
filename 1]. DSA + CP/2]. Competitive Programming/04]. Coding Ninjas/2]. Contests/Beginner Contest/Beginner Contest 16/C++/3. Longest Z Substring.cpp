/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the length of the string 'S'.
*/

#include <string>
#include <queue>
using namespace std;

int longestZSubstring(int k, string s) {

    // Initializing 'n', the length of the string 's'.
    int n = s.size();

    // Initializing 'ans', which stores the answer with '0'.
    int ans = 0;

    /* Creating variables 'i' and 'j', denoting the starting and ending points 
    of the current substring. */
    int i = 0, j = -1;

    /* Creating a deque 'q' which stores the positions of the characters 
    that are not 'Z' int the current substring. */
    deque<int> q;

    while (j < n) {

        /* Checking if the current substring is valid, and then 
        updating the answer and incrementing the ending point. */
        if (q.empty() or q.front() - q.back() < k) {
            ans = max(ans, j - i + 1);
            j++;
        }

        // Incrementing both the starting and ending points if the current substring is not valid.
        else {

            // Updating the positions stored in 'q' before moving the starting point.
            if (s[i] != 'Z') q.pop_back();
            i++;
            j++;
        }

        if (j == n) break;

        // Updating the positions stored in 'q' after moving the ending point.
        if (s[j] != 'Z') q.push_front(j);
    }

    // Returning the final answer stored in 'ans'.
    return ans;
}
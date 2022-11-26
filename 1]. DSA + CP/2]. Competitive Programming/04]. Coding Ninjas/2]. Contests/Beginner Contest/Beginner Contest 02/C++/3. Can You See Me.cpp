/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' denotes the number of elements in the array 'ARR'.
*/

int countPairs(int n, vector<int> &arr) {

    // 'ans' stores the final answer.
    int ans = 0;

    // Declare a stack 'st'.
    stack<int> st;

    // Iterate over all the elements in the array 'ARR'.
    for (int i = 0; i < n; ++i) {

        // While the stack 'st' is not empty and the top element is smaller than current element.
        while (!st.empty() && st.top() < arr[i]) {

            // Pop from the stack.
            st.pop();

            // Increment 'ans' by '1'.
            ans++;
        }

        // If the stack 'st' is empty.
        if (!st.empty()) {

            // Increment 'ans' by '1'.
            ans++;

            // If the top element of the stack 'st' is not equal to the current element.
            if (st.top() != arr[i]) {

                // Push the current element to the stack 'st'.
                st.push(arr[i]);
            }
        } else {

            // Otherwise, push the element to the stack.
            st.push(arr[i]);
        }
    }

    // Return the answer 'ans'.
    return ans;
}
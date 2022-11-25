/*
    Time complexity: O(N * LogN)
    Space complexity: O(N)

    Where 'N' is the number of operations.
*/

#include <queue>
vector<pair<int, int>> satisfiedHeap(int n, vector<pair<int, int>> &operations) {
    // Initializing empty pair vector 'answer'.
    vector<pair<int, int>> answer;
    // Initializing 'heap'.
    priority_queue<int> heap;

    // Iterating over the 'operations'.
    for (int i = 0; i < operations.size(); i++) {
        // Initializing the variable 'x'.
        int x = operations[i].second;

        // Checking for all conditions one by one.
        if (operations[i].first == 1) {
            heap.push(-x);
            answer.push_back({1, x});
        } else if (operations[i].first == 2) {
            // Checking for min possibilities.
            while (!heap.empty() && -heap.top() < x) {
                heap.pop();
                answer.push_back({3, -1});
            }
            if (heap.empty() || -heap.top() > x) {
                heap.push(-x);
                answer.push_back({1, x});
            }
            answer.push_back({2, x});
        } else {
            // Checking for erase possibilities.
            if (heap.empty()) {
                answer.push_back({1, 0});
            } else {
                heap.pop();
            }
            answer.push_back({3, -1});
        }
    }
    // Returning 'answer'.
    return answer;
}

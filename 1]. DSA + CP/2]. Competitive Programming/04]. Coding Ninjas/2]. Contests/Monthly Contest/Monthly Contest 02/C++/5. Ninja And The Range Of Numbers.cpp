/*
    Time complexity: O(M * log(N))
    Space complexity: O(M)

    Where 'N' is number of integers between 'L' and 'R' i.e 'N' = 'R - L + 1' and 'M' is the total number of magic numbers 'M ~ 600000'.
*/

// Recursive function to get all magical numbers till '1e12'.
void get(int pos, int cnt, long long cur, vector<long long> &numbers) {
    // Base case.
    if (pos == 12) {
        numbers.push_back(cur);
        return;
    }

    // Exclude case.
    get(pos + 1, cnt, cur * 10, numbers);

    // Include case.
    if (cnt < 3) {
        for (int i = 1; i <= 9; ++i) {
            get(pos + 1, cnt + 1, cur * 10 + i, numbers);
        }
    }
}

long long countMagicNumbers(long long l, long long r) {
    // Initializing the vector 'numbers' to store all numbers.
    vector<long long> numbers;

    // Calling recursion.
    get(0, 0, 0, numbers);
    numbers.push_back(1000000000000);

    // Updating the 'answer'.
    long long answer = (long long)(upper_bound(numbers.begin(), numbers.end(), r) - lower_bound(numbers.begin(), numbers.end(), l));
    return answer;
}

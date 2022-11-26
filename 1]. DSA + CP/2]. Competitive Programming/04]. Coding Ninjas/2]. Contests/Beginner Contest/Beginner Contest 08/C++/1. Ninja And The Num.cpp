/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the size of the input string 'num'.
*/

string maximumNum(int n, string num, vector<int> &a) {
    // Initializing the array 'diff'.
    vector<int> diff;

    // Updating the array 'diff'.
    for (int i = 0; i < n; i++) {
        diff.push_back(a[num[i] - '0'] - (num[i] - '0'));
    }

    // Iterating over the 'num' and checking if there is any profit move.
    for (int i = 0; i < n; i++)
        // If there is any profit move do it.
        if (diff[i] > 0) {
            while (i < n && diff[i] >= 0) {
                num[i] = char(a[num[i] - '0'] + '0');
                i++;
            }
            break;
        }
    return num;
}
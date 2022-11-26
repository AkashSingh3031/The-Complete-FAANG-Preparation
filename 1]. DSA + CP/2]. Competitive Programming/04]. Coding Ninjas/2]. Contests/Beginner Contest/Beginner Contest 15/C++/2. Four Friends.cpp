/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the size of the array.
*/

string fourFriends(string& s)
{
    int n = s.length();

    // We calculate the total number of blocks of four lengths.
    int blocks = n / 4;
    vector<int> count(4, 0);

    // Iterating over the string to calculate the score.
    for (int block = 0; block < blocks; block++) {
        int start = block * 4;
        int curScore = 0;

        // Calculating the score for the current block.
        for (int i = start; i < start + 4; i++) {
            if (s[i] == '1') {
                curScore++;
            }
        }

        // Adding the current score to the 'block % 4' starting position.
        count[block % 4] += curScore;
    }
    int mx = 0;

    // Calculating the maximum element.
    for (int i = 0; i < 4; i++) {
        mx = max(mx, count[i]);
    }
    int mxEleCount = 0;
    int ind = 0;
    for (int i = 0; i < 4; i++) {
        if (mx == count[i]) {
            mxEleCount++;
            ind = i + 1;
        }
    }

    // If the maximum element is occurring more than once then we return 'NO'.
    if (mxEleCount > 1) {
        return "NO";
    }

    // Else we joined "YES" and the position.
    string ans = "YES " + to_string(ind);

    // We are returning the answer here.
    return ans;
}
/*
    Time Complexity: O(Max(N, M))
    Space Complexity: O(1)

    Where 'N' is the length of the String 'A' and 'M' is the length of the String 'B'.
*/


int addingBinaryToString(string &a, string &b) {

    int countOfZeroesInA = 0, countOfOnesInA = 0;

    // Iterate over the string 'A'.
    int n = a.length();
    for (int i = 0; i < n; i++) {

        // If current character is '0' increment 'countOfZeroesInA'.
        if (a[i] == '0') {
            countOfZeroesInA++;
        }

        // Else increment 'countOfOnesInA'.
        else {
            countOfOnesInA++;
        }

    }
    int countOfZeroesInB = 0, countOfOnesInB = 0;

    // Iterate over the string 'B'.
    int m = b.length();
    for (int i = 0; i < m; i++) {

        // If current character is '0' increment 'countOfZeroesInB'.
        if (b[i] == '0') {
            countOfZeroesInB++;
        }

        // Else increment 'countOfOnesInB'.
        else {
            countOfOnesInB++;
        }
    }

    // If count of both '0' and '1' is less or equal in string 'A', then return true.
    if (countOfZeroesInA <= countOfZeroesInB and countOfOnesInA <= countOfOnesInB) {
        return true;
    }

    // Else return False.
    else {
        return false;
    }
}

/*
    Time Complexity : O(1)
    Space Complexity : O(1)

*/

int ninjaDish(int a, int b, int c) {

    // Initialise 'ans' as the maximum total dishes possible.
    int ans = 0;

    // Total units of Soup possible.
    int X = min(a, b);

    ans += X;

    // Update the left amount of Pepper.
    b -= X;

    // Add units of Pasta possible.
    ans += min(b, c);

    // Return the final result.
    return ans;
}

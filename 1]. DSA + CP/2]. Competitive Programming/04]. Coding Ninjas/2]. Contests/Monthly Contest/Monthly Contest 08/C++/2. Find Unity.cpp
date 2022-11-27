/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where 'N' is the size of the array 'X'.

*/

int findUnity(int n, vector<int> x)
{
    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        // Keep multiplying he unit digit of every element of the array and the unit digit of 'ans'.
        ans = (ans%10) * (x[i]%10);
    }

    // Find the unit digit of 'ans' by using modulo operator.
    ans %= 10;

    // Return 'ans' as the final output.
    return ans;
}

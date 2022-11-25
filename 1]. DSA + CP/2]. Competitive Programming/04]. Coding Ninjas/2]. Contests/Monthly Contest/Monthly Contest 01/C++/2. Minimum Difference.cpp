/*
    Time Complexity: O(N)
    Space Complexity: O(1)
    where 'N' is the number of elements.
*/

int minimumDifference(int n, vector<int> arr)
{
    int countOnes = 0;

    // Count number of 1s.
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 1)
        {
            countOnes++;
        }
    }

    // If countOnes is odd.
    if (countOnes % 2 == 1)
    {
        // Return 1.
        return 1;
    }

    // If countOnes is even.
    else
    {
        // Return 0.
        return 0;
    }
}

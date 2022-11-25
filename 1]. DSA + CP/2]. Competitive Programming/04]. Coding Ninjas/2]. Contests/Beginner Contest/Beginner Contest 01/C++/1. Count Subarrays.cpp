/*
    Time Complexity: O(N)
    Space Complexity: O(1)
    where 'N' is the number of elements.
*/

int numberOfSubarrays(int n, vector<int> arr)
{
    // Stores number of valid subarrays.
    int count = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        // If adjacent elements not equal, it's a valid subarray.
        if (arr[i] != arr[i + 1])
        {
            // Increment count.
            count++;
        }
    }

    // Return count.
    return count;
}

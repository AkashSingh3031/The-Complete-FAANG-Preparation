/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(1)

    where 'N' is the size of the array 'A'.
*/

int maxPrefix(int k, vector<int> a)
{
    // Sorting 'a' in non-increasing order.
    sort(a.begin(), a.end(), greater<int>());

    // Creating 'ans'.
    int ans = 0;

    // Calculating answer.
    for (int i = 0; i < k; i++)
    {
        ans += a[i];
    }

    // We are returning the answer here.
    return ans;
}
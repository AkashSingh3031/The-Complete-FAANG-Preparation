/*
   Time Complexity: O(n)
   Space Complexity: O(n)

   where n is the length of all the array arr and q is the number of queries.
*/

bool checkBeautiful(int n, int k, int m, vector<int> height)
{
    int ans = n - 1;
    vector<int> pre(n, 0);
    vector<int> suf(n, 0);

    // Calculating if the prefix is sorted.
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || height[i] >= height[i - 1])
        {
            pre[i] = 1;
            ans = min(ans, n - 1 - i);
        }
        else
        {
            break;
        }
    }

    // Calculating if the suffix is sorted.
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1 || height[i] <= height[i + 1])
        {
            suf[i] = 1;
            ans = min(ans, i);
        }
        else
        {
            break;
        }
    }

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (pre[i] == 1)
        {
            // Using two-pointers to find the minimum length sub-array
            // that has to be removed.
            j = max(i + 1, j);
            while (j < n)
            {

                if (suf[j] == 0)
                {
                    j += 1;
                    continue;
                }
                else if (suf[j] == 1 && height[i] <= height[j])
                {
                    ans = min(ans, j - i - 1);
                    break;
                }
                else
                {
                    j += 1;
                }
            }
        }
        else
        {
            break;
        }
    }

    if (ans * m <= k)
    {
        return true;
    }

    return false;
}
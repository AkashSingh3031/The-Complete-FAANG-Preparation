/*
	Time Complexity: O(|S|)
	Space Complexity: O(1)

	where |S| is the length of the given string.
*/

bool isPoss(int mid, vector<int> &freq, int n)
{
    int reqN = 0;
    if (mid == 0)
    {
        return false;
    }

    for (int i : freq)
    {
        // Taking ceil of (i/mid).
        if (i > 0)
            reqN += (i + mid - 1) / mid;
    }

    if (reqN <= n)
    {
        return true;
    }

    return false;
}

int minX(string &s, int n)
{
    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'a']++;
    }

    int l = 0, r = s.length(), mid = 0, ans = s.length();
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (isPoss(mid, freq, n))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

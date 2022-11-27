/*
	Time Complexity: O(N * logN)
	Space Complexity: O(1)

	where 'N' is the number of tasks given in the problem.
*/

int possTasks(int n, int a, int b, vector<int> &c)
{
    if(a + b > n)
    {
        return 0;
    }
    
    // Sorting the complexity array.
    sort(c.begin(), c.end());
    int ans = c[n-a] - c[b-1];
    return ans;
}
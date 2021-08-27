int maxSubarraySum(int arr[], int n)
    {
        int sum = 0;
        int best = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            sum = max(arr[i], sum + arr[i]);
            best = max(best, sum);
        }
        return best;
    }

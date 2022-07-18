int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
    int res = arr[0], l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        l =  (l ? l : 1) * arr[i];
        r =  (r ? r : 1) * arr[n - 1 - i];
        res = max(res, max(l, r));
    }
    return res;
}

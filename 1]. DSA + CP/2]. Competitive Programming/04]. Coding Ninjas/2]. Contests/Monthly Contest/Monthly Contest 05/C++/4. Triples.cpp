/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(1)

    where 'N' is the length of the array.
*/

long long triple(vector<int> &a){
    int n = a.size();

    // Sort the array in non decreasing order.
    sort(a.begin(), a.end());

    // Initializing variable 'ans' with 0 and left pointer 'j' with 0.
    long long ans = 0;
    int j = 0;

    // Calculating 'ans'.
    for (int i = 0; i < n; i++){
        while (a[i] - a[j] > 2){
            j++;
        }
        if (i - j < 2){

            // We cannot make a triple.
            continue;
        }
        long long x = i - j;
        ans += (x * (x - 1)) / 2;
    }

    // We are returning our answer here.
    return ans;
}
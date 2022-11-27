/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the length of the array.
*/

int lostX(vector<int> &a){
    int n = a.size();

    // Initializing variable 'mx' with 0 which stores the maximum element.
    int mx = 0;

    // Finding maximum element.
    for (int i = 0; i < n; i++){
        mx = max(mx, a[i]);
    }

    // We are returning our answer here.
    return mx;
}
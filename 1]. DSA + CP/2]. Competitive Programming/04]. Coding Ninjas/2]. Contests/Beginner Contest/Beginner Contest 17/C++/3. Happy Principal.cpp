/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the length of the array.
*/

int happyPrincipal(vector<int> &a){
    int n = a.size();

    // Creating a hashmap 'occ' with [key,value] pair as [integer,integer].
    unordered_map<int, int> occ;

    // Creating variable 'mxOcc' for storing maximum occurrence among the occurrences of the element.
    int mxOcc = 0;

    // Finding maximum occurrence.
    for (int i = 0; i < n; i++){
        occ[a[i]]++;
        mxOcc = max(mxOcc, occ[a[i]]);
    }

    // Creating variable 'ans' to store our answer.
    int ans = n - mxOcc;

    // We are returning our answer here.
    return ans;
}
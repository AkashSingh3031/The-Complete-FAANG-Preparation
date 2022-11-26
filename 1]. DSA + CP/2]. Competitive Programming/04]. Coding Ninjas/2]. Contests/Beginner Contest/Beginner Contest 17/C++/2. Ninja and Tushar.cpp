/*
    Time Complexity: O(N log(N))
    Space Complexity: O(1)

    where 'N' is the size of the array.
*/

int findDifference(vector<int> &v){
    int n = v.size();

    // To take gems with larger power first, sort the vector in decreasing order.
    sort(v.begin(), v.end(), greater<int>());

    // Creating two variables for storing power of Ninja and Tushar.
    int ninjaPower = 0, tusharPower = 0;

    // We know that Ninja starts first.
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            ninjaPower += v[i];
        }else{
            tusharPower += v[i];
        }
    }
    int ans = ninjaPower - tusharPower;

    // We are returning the answer here.
    return ans;
}
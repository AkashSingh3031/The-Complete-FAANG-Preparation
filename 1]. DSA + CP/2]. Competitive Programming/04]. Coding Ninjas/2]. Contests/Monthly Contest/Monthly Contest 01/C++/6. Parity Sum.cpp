/*
    Time complexity: O(N*logN)
    Space complexity: O(N)

    Where 'N' is the size of the given array.
*/

// BIT query function to get sum of all A[j] > A[i].
long query(int x, int n, vector<long> &bit) {

    long ans = 0;

    for (int i = x; i <= n; i += (i & (-i))) {
        ans += bit[i];
    }

    return ans;
}

// Update the current value A[i] in BIT.
void update(int x, long val, vector<long> &bit) {
    for (int i = x; i > 0; i -= (i & (-i))) {
        bit[i] += val;
        
    }
}

// Function to apply Coordinate Compression on an array.
void coordinateCompress(vector<int> &arrVal) {

    map<int,int> mapping;
    // Mark each unique value in map.
    for (int x: arrVal) {
        mapping[x] = 1;
    }

    int val = 1;

    // Assign each marking a unique value according to order.
    for (auto &keys: mapping) {
        keys.second = val;
        val += 1;
    }

    // Compress the co-ordinates using mapping.
    for(auto &x : arrVal){
        x = mapping[x];
    }

}

vector<int> paritySum(vector<int> A, int n, int m){
    
    vector<int> res(n);

    map<int,vector<int>> groups;

    // Traverse the array from left to right.
    for (int i = 0; i < n; i++) {
        // Append in corresponding group.
        groups[A[i]%m].push_back(i);
    }

    /*
       Problem now becomes given a group arr
       find the sum of all 'A[j]' such that
       'j' < 'i' and 'arr[j]' > 'arr[i]'.
    */

    for (auto group : groups) {

        vector<int> arr = group.second;
        
        vector<int> arrVal;

        for (int id: arr) {
            arrVal.push_back(A[id]);
        }
        coordinateCompress(arrVal);

        // Create a new BIT according to size of arr.
        int size = arrVal.size();
        
        vector<long> bit(size + 1);
        for (int i = 0; i < arr.size();i++) {
            int id = arr[i];
            long x = arrVal[i];

            // Query the sum of all 'y' > 'x'.
            long sum = query(x + 1, size, bit);
            
            res[id] = (int)sum % 2;

            // Update the value of 'x' to BIT.
            update(x, A[id], bit);
        }
    }
    // Return the final result.
    return res;
}

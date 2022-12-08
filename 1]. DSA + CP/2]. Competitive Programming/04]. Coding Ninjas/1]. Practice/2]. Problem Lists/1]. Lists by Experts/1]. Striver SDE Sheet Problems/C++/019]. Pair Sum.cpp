#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<int> res;
    vector<vector<int>> r;
    unordered_map<int, int> seen;
    int n = arr.size();
    for(int i=0; i<n; i++) {
        if(seen.find(s-arr[i]) != seen.end()) {
            int temp = seen.find(s-arr[i])->second;
            while(temp--) {
                res.push_back(s-arr[i]);
                res.push_back(arr[i]);
                sort(res.begin(), res.end());
                r.push_back(res);
                res.clear();
            }
        }
        seen[arr[i]]++;
    }
    sort(r.begin(), r.end());
    return r;
}

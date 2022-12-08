#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    unordered_map<int, pair<int, int>> seen;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int twoSum = arr[i] + arr[j];
            seen[twoSum] = {i, j};
        }
    }
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int left = target - (arr[i] + arr[j]);
            if(seen.find(left) != seen.end()) {
                pair<int, int> it = seen[left];
                    int front = it.first;
                    int back = it.second;               
                    if(i != front and i != back and j != front and j != back)
                        return "Yes";
            }
        }
    }
    return "No"; 
}

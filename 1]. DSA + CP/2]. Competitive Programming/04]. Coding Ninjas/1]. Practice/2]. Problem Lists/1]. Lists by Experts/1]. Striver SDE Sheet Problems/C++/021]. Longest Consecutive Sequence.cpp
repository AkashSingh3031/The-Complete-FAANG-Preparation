#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> num;
    int ans = 0;
        
    for(int i : arr) {
        num.insert(i);
    }
        
    for(int i : arr) {
        if(!num.count(i-1)) {
            int count = 1;
            while(num.count(i+count)) {
                count++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}

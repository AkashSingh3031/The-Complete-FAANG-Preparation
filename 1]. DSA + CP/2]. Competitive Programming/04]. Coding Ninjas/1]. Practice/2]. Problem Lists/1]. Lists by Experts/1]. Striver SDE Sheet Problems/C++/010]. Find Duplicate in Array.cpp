#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
    // Write your code here.
    int slow = arr[0], fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    
    fast = arr[0];
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

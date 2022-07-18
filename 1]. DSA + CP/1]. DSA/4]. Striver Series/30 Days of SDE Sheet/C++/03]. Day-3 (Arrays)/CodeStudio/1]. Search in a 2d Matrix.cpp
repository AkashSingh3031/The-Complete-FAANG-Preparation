#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    int left = 0, right = m*n-1;
    while(left != right) {
        int mid = (left + (right - left)/2);
        if(mat[mid/n][mid%n] < target)
            left = mid+1;
        else
            right = mid;
    }
    return mat[right/n][right%n] == target;
}

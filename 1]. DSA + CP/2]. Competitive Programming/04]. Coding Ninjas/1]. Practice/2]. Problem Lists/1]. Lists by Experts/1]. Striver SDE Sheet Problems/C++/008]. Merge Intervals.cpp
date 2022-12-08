#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
        
    for(int i=0; i<intervals.size(); i++) {
        if(res.empty() || res.back()[1] < intervals[i][0]) {
            vector<int> v = {intervals[i][0], intervals[i][1]};
            res.push_back(v);
        }
        else {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
    }
    return res;
}

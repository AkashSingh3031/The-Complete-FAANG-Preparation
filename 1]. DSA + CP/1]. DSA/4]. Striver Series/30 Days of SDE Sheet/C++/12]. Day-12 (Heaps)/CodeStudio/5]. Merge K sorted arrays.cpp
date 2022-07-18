#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    for(int i=0; i<k ; i++){
        for(int j=0; j< kArrays[i].size(); j++){
            minh.push(kArrays[i][j]);
        }
    }
    vector<int> res;
    while(minh.size() > 0) {
        res.push_back(minh.top());
        minh.pop();
    }  
    return res;
}
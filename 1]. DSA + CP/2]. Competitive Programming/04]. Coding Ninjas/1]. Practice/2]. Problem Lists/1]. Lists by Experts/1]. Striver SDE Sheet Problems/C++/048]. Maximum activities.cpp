#include <bits/stdc++.h>

struct job{
    int start; 
    int end;
};
bool comp(struct job a, struct job b){
    return (a.end < b.end);
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n=start.size();
    struct job v[n];
    
    for(int i=0; i<n; i++){
        v[i].start = start[i];
        v[i].end = finish[i];
    }
    
    sort(v, v+n, comp);
    int ans = 1;
    int end = v[0].end;
    for(int i=1; i<n; i++){
        if(v[i].start >= end){
            end = v[i].end;
            ans++;
        }
    }
    return ans;
}
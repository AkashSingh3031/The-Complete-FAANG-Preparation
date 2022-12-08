#include<bits/stdc++.h>
struct meeting{
    int startTime;
    int endTime;
    int pos;
};
bool comparator(struct meeting m1,meeting m2){
    if(m1.endTime < m2.endTime) 
        return true;
    else if(m1.endTime > m2.endTime) 
        return false;
    else if(m1.pos < m2.pos) 
        return true;
    else 
        return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].startTime = start[i];
        meet[i].endTime = end[i];
        meet[i].pos = i+1;
    }
    sort(meet, meet+n, comparator);
    vector<int> ans;
    int ending = meet[0].endTime;
    ans.push_back(meet[0].pos);
    for(int i=1; i<n; i++){
        if(meet[i].startTime > ending){
            ending = meet[i].endTime;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}
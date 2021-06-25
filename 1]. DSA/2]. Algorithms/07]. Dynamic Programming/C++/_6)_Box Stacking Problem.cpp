	#include<bits/stdc++.h>
using namespace std;
bool canPlaceBoxes(vector<int>b1,vector<int>b2){
    if(b1[0]>b2[0]&&b1[1]>b2[1]&&b1[2]>b2[2])
        return true;
    return false;
}
bool BoxCompare(vector<int>b1, vector<int>b2){
    return b1[2]>b2[2];
}
int box_stacking(vector<vector<int>>&boxes){
    //sorting the boxes based on their heights
    //creating a custom compare function 
    sort(boxes.begin(),boxes.end(),BoxCompare);
    int n=boxes.size();
    vector<int>dp(n+1,0);
    //filling dp array with the heights
    for(int i=0;i<n;i++){
        dp[i]=boxes[i][2];
    }
    //bottom up approach
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            //canPlaceBoxes function checks whether h`<h , w`<w and d`<d
            if(canPlaceBoxes(boxes[j],boxes[i])){
                int current_height=boxes[i][2];
                //taking jth box as the bottom, checking whether the height is maximum
                //if this is true we stack the previous max height boxes over this
                // this is the step where we need to use the previous results to get the current result
                if(dp[j]+current_height>dp[i]){
                    dp[i]=dp[j]+current_height;
                }
            }
        }
    }
    int max_height=INT_MIN;
    for(int i=0;i<n;i++){
        max_height=max(max_height,dp[i]);
    }
    return max_height;
}
int main(){
    vector<vector<int>> boxes={
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5},
    };
    //ans should be 10
    int height=box_stacking(boxes);
    cout<<"Max Height"<<" "<<height<<endl;
}

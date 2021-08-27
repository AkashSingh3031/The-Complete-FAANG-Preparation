#include<bits/stdc++.h>
using namespace std;

void merge(vector<vector<int>>& intervals) 
  {
    vector<vector<int>> res;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    res.push_back(intervals[0]);

    for(int i = 1; i < n; i++)
    {
        if(intervals[i][0] <= res.back()[1])
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        else
            res.push_back(intervals[i]);
    }

  n = res.size();
  vector<vector<int>> intervals;
  for(int i = 0; i < n; i++)
    cout<<"[ "<<res[i][0]<<" ,"<<res[i][1]<<" ]";
    
}
// Driver program
int main()
{
  int n;
  cin>>n;
  
  vector<vector<int>> intervals;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < 2; j++)
      cin>>intervals[i][j];
	merge(intervals);
	return 0;
}

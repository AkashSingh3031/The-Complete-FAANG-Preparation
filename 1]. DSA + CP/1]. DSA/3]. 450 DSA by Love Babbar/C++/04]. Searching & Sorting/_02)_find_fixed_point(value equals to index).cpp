#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> valueEqualToIndex(int arr[], int n)
  {
    // code here
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == i + 1)
      {
        v.push_back(arr[i]);
      }
    }
    return v;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, i;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
      cin >> ar[i];
    }
    Solution obj;
    auto ans=obj.valueEqualToIndex(ar,n);
    if(ans.empty())
    {
      cout<<"Not Found"<<endl;
    }
    else
    {
      for(int x:ans)
        cout<<x<<endl;
    }
  }
  return 0;
}
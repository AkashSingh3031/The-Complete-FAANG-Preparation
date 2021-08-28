#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int n)
{
      vector<vector<int>> res;
      for (int line = 1; line <= n; line++)
      {
          int C = 1; // used to represent C(line, i)
          vector<int> temp;
          for (int i = 1; i <= line; i++)
          {
              // The first value in a line is always 1
              temp.push_back(C);
              C = C * (line - i) / i;
          }
          res.push_back(temp);
      }

      return res;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> res = generate(n);
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
           cout<<res[i][j]<<" ";
           
        cout<<"\n";   
    }

    return 0;
}

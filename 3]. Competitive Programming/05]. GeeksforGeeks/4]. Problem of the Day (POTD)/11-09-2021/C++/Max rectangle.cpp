#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution
{
  public:
    int maxHist(int row[], int m)
    {
        stack<int> result;
        int top_val; 
        int max_area = 0; 
        int area = 0; 
        int i = 0;
        
        while (i < m) 
        {
            if (result.empty() || row[result.top()] <= row[i])
                result.push(i++);
     
            else
            {
                top_val = row[result.top()];
                result.pop();
                area = top_val * i;
     
                if (!result.empty())
                    area = top_val * (i - result.top() - 1);
                max_area = max(area, max_area);
            }
        }
     
        while (!result.empty()) 
        {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
     
            max_area = max(area, max_area);
        }
        return max_area;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) 
    {
        // Your code here
        int result = maxHist(M[0], m);
 
        for (int i = 1; i < n; i++) 
        {
            for (int j = 0; j < m; j++)
                if (M[i][j])
                    M[i][j] += M[i - 1][j];
            result = max(result, maxHist(M[i], m));
        }
        return result;
    }
};

int main() 
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) 
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                cin >> M[i][j];
            
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

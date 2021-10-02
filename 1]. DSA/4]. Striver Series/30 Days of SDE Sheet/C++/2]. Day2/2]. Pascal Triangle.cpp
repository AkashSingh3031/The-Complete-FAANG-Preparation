#include <bits/stdc++.h>
using namespace std;
// Function to find the elements of rowIndex in Pascal's Triangle
vector<int> getRow(int rowIndex)
{
     vector<int> currow;
     // 1st element of every row is 1
     currow.push_back(1);

     // Check if the row that has to
     // be returned is the first row
     if (rowIndex == 0)
       return currow;
	
     // Generate the previous row
     vector<int> prev = getRow(rowIndex - 1);

     for(int i = 1; i < prev.size(); i++)
     {
        int curr = prev[i - 1] + prev[i];
        currow.push_back(curr);
     }
     currow.push_back(1);

     // Return the row
     return currow;
}

// Driver Code
int main()
{
	int n;
 cin>>n;
	vector<int> arr = getRow(n);

  for(int i = 0; i < arr.size(); i++)
  {
     if (i == arr.size() - 1)
      cout << arr[i];
     else
      cout << arr[i] << ", ";
  }
  return 0;
}

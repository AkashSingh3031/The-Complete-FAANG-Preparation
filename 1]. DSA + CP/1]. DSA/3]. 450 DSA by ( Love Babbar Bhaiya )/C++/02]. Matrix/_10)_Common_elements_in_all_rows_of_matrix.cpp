//Link:  https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/
/*
Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.
Example: 

Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output: 
1 8 or 8 1
8 and 1 are present in all rows.*/
 
#include <iostream>
#include <unordered_map>
using namespace std;

void commonElements(int arr[][100], int m, int n)
{
    unordered_map<int, int> matrixMap;
    for (int i = 0; i < n; i++)
    {
        matrixMap[arr[0][i]] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrixMap[arr[i][j]] == i)
            {
                matrixMap[arr[i][j]] = i + 1;
                if (i == m - 1)
                {
                    cout << arr[i][j] << " ";
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    int arr[100][100];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    commonElements(arr, m, n);
    return 0;
}
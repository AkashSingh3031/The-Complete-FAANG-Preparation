/*  We are given two 32 bit numbers M And N and two bit positions i and j. 
    We have to set all bits between i and j in N equal to M.

    Example: N = 10000000000, M = 10101, i = 2, j = 6
            Output: N = 10001010100
*/

#include <bits/stdc++.h>
using namespace std;

int ClearRangeItoJ(int n, int i, int j)
{
    int ones = (~0);
    int a = ones << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    int ans = n & mask;
    return ans;
}

int ReplaceBits(int n, int m, int i, int j)
{
    int n1;
    n1 = ClearRangeItoJ(n, i, j);
    int ans = n1 | (m << i);
    return ans;
}

int main()
{
    int n = 15, m = 2, i = 1, j = 3;
    cout << ReplaceBits(n, m, i, j);
    return 0;
}
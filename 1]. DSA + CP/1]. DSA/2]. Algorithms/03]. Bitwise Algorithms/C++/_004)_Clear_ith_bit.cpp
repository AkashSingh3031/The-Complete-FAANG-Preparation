// Clear ith bit of a number

#include <bits/stdc++.h>
using namespace std;

void ClearBit(int &n, int i) // value of n is passed by refrence so we dont have to return its value
{
    int mask = ~(1 << i);
    n = n & mask;
}

int main()
{
    int n = 7, i = 2;

    ClearBit(n, i);
    cout << n;

    return 0;
}

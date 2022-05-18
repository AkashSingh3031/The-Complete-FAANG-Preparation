// All power of two numbers has only a one-bit set. So count the no. of set bits and if you get 1 then the number is a power of 2.

#include <bits/stdc++.h>
using namespace std;

int CountBits(int n)
{
    int c = 0;

    while (n > 0)
    {
        n = n & (n - 1);
        c++;
    }
    return c;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if (CountBits(n) == 1)
    {
        cout << "Power of 2" << endl;
    }
    else
    {
        cout << "Not a power of 2" << endl;
    }

    return 0;
}
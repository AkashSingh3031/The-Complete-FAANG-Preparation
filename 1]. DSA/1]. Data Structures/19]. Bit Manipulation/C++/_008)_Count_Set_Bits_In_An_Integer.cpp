#include <bits/stdc++.h>
using namespace std;

int Countbits(int n)
{
    int c = 0;

    while (n > 0)
    {
        c = c + (n & 1);
        n = n >> 1;
    }

    return c;
}

int CountbitsFast(int n)
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

    // Method-1 (Inbuilt function in STL)
    cout << __builtin_popcount(n) << endl;

    // Method-2
    cout << Countbits(n) << endl;

    // Method- 3 (Brian Kernighan’s Algorithm)
    cout << CountbitsFast(n) << endl;
    return 0;
}
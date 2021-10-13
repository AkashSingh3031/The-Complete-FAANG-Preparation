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

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    // Method-2
    cout << Countbits(n) << endl;
    
    return 0;
}

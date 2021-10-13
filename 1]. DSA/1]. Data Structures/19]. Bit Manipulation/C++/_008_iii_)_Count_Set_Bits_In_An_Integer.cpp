#include <bits/stdc++.h>
using namespace std;

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

    // Method- 3 (Brian Kernighan’s Algorithm)
    cout << CountbitsFast(n) << endl;
    
    return 0;
}

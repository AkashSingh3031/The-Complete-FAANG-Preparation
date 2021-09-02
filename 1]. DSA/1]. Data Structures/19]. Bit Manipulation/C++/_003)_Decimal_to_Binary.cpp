// Convert a decimal number to its binary form

#include <bits/stdc++.h>
using namespace std;

int DecimalToBinary(int n)
{
    int ans = 0, p = 1;
    while (n > 0)
    {
        int last_bit = (n & 1);
        ans += p * last_bit;

        p = p * 10;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << DecimalToBinary(n) << endl;
    return 0;
}
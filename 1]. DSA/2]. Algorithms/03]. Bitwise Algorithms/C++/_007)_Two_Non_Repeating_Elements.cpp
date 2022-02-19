#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, num, ans = 0;
    int a[1000];

    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a[i] = num;
        ans = ans ^ num;
    }

    int temp = ans;
    int pos = 0;

    // Find the position of the set bit and divide the array into 2 parts.
    while ((temp & 1) != 1)
    {
        pos++;
        temp = temp >> 1;
    }

    int mask = 1 << pos;

    int p = 0, q = 0;

    for (int i = 0; i < n; i++)
    {
        // Dividing the array
        if (a[i] & mask)
        {
            p = p ^ a[i];
        }
        else
        {
            q = q ^ a[i];
        }
    }

    cout << p << " " << q << endl;

    return 0;
}
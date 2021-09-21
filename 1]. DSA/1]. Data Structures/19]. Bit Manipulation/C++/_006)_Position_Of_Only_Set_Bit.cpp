/*

    1. Check if the number is power of 2 or not (to check if there is only one set bit or not).
    2. If it is not a power of 2 then return -1.
    3. Else one by one move the only set bit to right till it reaches end and count the position.

*/

#include <bits/stdc++.h>
using namespace std;

int power_of_two(int n)
{
    int c = 0;

    while (n > 0)
    {
        n = n & (n - 1);
        c++;
    }

    return c;
}

int position_Of_set_bit(int n)
{
    if (power_of_two(n) != 1)
        return -1;

    int pos = 0;

    while (n > 0)
    {
        n = n >> 1;
        // Since we have to start position from 1
        ++pos;
    }

    return pos;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << position_Of_set_bit(n) << endl;

    return 0;
}

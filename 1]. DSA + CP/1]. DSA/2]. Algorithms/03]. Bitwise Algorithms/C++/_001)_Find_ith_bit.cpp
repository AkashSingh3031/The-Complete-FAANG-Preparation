#include <bits/stdc++.h>
using namespace std;

int getbit(int n, int i)
{
    int mask = 1 << i;
    int bit = (n & mask) > 0 ? 1 : 0;
    return bit;
}
int main()
{
    int n, i;
    cout << "Enter The Number: ";
    cin >> n;
    cout << "Enter the value of i: ";
    cin >> i;
    cout << getbit(n, i) << endl;
    return 0;
}
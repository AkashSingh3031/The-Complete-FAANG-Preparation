#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    // Method-1 (Inbuilt function in STL)
    cout << __builtin_popcount(n) << endl;

    return 0;
}

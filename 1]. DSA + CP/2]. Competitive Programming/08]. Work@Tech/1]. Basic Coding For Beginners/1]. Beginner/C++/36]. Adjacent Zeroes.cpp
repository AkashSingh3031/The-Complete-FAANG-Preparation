#include <bits/stdc++.h>
using namespace std;


bool hasAdjacentZeroes(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0' && s[i-1] == '0') {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        if (hasAdjacentZeroes(n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

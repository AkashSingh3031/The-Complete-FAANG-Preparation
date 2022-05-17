/*
Example 1:
	Input:
		N = 6
		A[] = {3, 2, 1, 56, 10000, 167}
	Output:
		min = 1, max =  10000
 
Example 2:
	Input:
		N = 5
		A[]  = {1, 345, 234, 21, 56789}
	Output:
		min = 1, max = 56789
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) {
    long long mn = a[0], mx = a[0];
    for(int i=0; i<n; i++) {
        if(a[i] > mx)
            mx = a[i];
        else if(a[i] < mn)
            mn = a[i];
    }
    return {mn, mx};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}

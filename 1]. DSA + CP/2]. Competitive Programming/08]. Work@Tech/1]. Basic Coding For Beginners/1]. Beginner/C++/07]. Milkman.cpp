#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int r, h;
	cin >> r >> h;
	float res = 40*(3.14*r*r*h)/1000;
	cout << fixed << setprecision(2);
	cout << res;
	return 0;
}
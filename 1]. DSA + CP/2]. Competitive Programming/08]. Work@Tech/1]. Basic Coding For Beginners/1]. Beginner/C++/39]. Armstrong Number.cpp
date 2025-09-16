#include <bits/stdc++.h>
using namespace std;

int order(int x)
{
    int n = 0;
    while (x) {
        n++;
        x = x / 10;
    }
    return n;
}

int intPow(int base, int exp) {
    int result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	int num;
    
	while(t--) {
		cin >> num;
		int n = order(num);
		int temp = num, sum = 0;
		while (temp) {
			int r = temp % 10;
			sum += intPow(r, n);
			temp = temp / 10;
		}

		if(sum == num)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
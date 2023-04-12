#include <bits/stdc++.h>
using namespace std;

int countDigit(int n)
{
    if (n == 0)
        return 0;
    return 1 + countDigit(n / 10);
}

bool check(int n)
{
    int l = countDigit(n);
    int dup = n;
    int sum = 0;

    while (dup)
    {
        sum += pow(dup % 10, l);
        dup /= 10;
    }
 
    return (n == sum);
}

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	
	while(t--) {
		cin >> n;
		if(check(n))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
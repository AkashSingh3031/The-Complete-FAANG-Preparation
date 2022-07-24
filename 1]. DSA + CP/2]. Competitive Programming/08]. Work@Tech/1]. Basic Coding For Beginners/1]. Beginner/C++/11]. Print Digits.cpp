<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

void printDigit(int N)
{
    int r;
    if (N == 0) 
        return;
    r = N % 10;
    printDigit(N / 10);
  
    cout << r << " ";
}

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	
	while(t--) {
		cin >> n;
		printDigit(n);
		cout << endl;
	}
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;

void printDigit(int N)
{
    int r;
    if (N == 0) 
        return;
    r = N % 10;
    printDigit(N / 10);
  
    cout << r << " ";
}

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	
	while(t--) {
		cin >> n;
		printDigit(n);
		cout << endl;
	}
	return 0;
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}
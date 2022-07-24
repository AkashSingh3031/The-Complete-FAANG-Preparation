<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

string isPalindrome(string S)
{
    string P = S;
    reverse(P.begin(), P.end());
 
    if (S == P) {
        return "True";
    }
    else {
        return "False";
    }
}

int main() {
	// your code goes here
	int t,r,sum=0,temp; 
	string n;
	cin>>t;
	while(t--) 
	{
		cin>>n;    
		cout << isPalindrome(n) << endl; 
	}  
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;

string isPalindrome(string S)
{
    string P = S;
    reverse(P.begin(), P.end());
 
    if (S == P) {
        return "True";
    }
    else {
        return "False";
    }
}

int main() {
	// your code goes here
	int t,r,sum=0,temp; 
	string n;
	cin>>t;
	while(t--) 
	{
		cin>>n;    
		cout << isPalindrome(n) << endl; 
	}  
	return 0;
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}
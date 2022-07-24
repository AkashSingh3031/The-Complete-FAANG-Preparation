<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    ch = toupper(ch);
    return (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	string str;
    while(t--)
	{
		cin >> str;
		int count = 0;
		for (int i=0; i<str.length(); i++) {
			if (isVowel(str[i])) {
				count += 1;
			}
		}
		cout << count << endl;
	}
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    ch = toupper(ch);
    return (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	string str;
    while(t--)
	{
		cin >> str;
		int count = 0;
		for (int i=0; i<str.length(); i++) {
			if (isVowel(str[i])) {
				count += 1;
			}
		}
		cout << count << endl;
	}
	return 0;
>>>>>>> cded02a3519e594c508657d8c349c299c5e1dfcc
}
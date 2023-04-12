#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	char str[100];
	int i, len, count = 0;
	gets(str);
	len = strlen(str);
	
	for (i = 0; i < len; i++)
		if (str[i] == ' ')
			count++;

	cout << count + 1;
	return 0;
}
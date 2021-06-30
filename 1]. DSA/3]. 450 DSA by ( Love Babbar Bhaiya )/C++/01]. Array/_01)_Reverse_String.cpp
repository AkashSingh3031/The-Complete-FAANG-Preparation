#include<bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        string s;
        cin >> s;
        cout << reverseWord(s) << endl;
	}
	return 0;
}

string reverseWord(string str){
    
  //Your code here
  int low=0, high=str.length()-1;
  
  while(low < high)
  {
      swap(str[low], str[high]);
      low++;
      high--;
  }
  return str;
}


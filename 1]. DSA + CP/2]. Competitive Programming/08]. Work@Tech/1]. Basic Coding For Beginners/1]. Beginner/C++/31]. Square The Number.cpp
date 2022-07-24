#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n, ans;
	cin >> t;
	
	while(t--) {
		cin >> n;
		string arr1 = to_string(n), arr2 = to_string(n); 

		reverse(arr1.begin(), arr1.end());
		reverse(arr2.begin(), arr2.end());

		int ans_size = arr1.size() + arr2.size();
		int ans[ans_size]={0};

		for(int i=0; i<arr1.size();i++)
		{
			for(int j=0; j<arr2.size();j++)
			{
				int p = (int)(arr1[i]) - '0';
				int q = (int)(arr2[j]) - '0';
				ans[i+j]+=p*q;
				ans[i+j+1]=ans[i+j+1]+ans[i+j]/10;
				ans[i+j]%=10;
			}
		}

		string s="";
		for(auto i=0;i<ans_size; ++i)
			s += to_string(ans[i]); 
		
		reverse(s.begin(), s.end() );
		if(s[0] =='0')
		{
		   string ss(s,1,s.size()-1);
		   s=ss;
		}
		cout << s << endl;
	}
	return 0;
}
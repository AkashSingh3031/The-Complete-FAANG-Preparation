//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> v;
		    int n = s.length();
		    int powSize = pow(2,n);
		    for(int countNo=0;countNo<powSize;countNo++)
		    {
		        string str ="";
		        for(int j=0;j<n;j++)
		        {
		            if((countNo & (1<<j))!=0){
		             str+=s[j];
		            }
		        }
		        
		         if(str.length()>0)
		         v.push_back(str);
		    }
		    sort(v.begin(),v.end());
		    return v;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
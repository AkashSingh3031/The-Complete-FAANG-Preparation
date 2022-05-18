#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> scores)
		{
		    // Code here.
		    size_t size = scores.size();

		    if (size == 0)
			return 0;  // Undefined, really.

		    else
		    {
			sort(scores.begin(), scores.end());
			if (size % 2 == 0)
			    return (scores[size / 2 - 1] + scores[size / 2]) / 2;
			else 
			    return scores[size / 2];
		    }
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        //Your code here
        int count[26] = {0};
        for(int i=0; i<S.size(); i++)
            count[S[i]-'a']++;
            
        for(int i=0; i<S.size(); i++)
            if(count[S[i]-'a']==1)
                return S[i];
        return '$';
    }
};

int main() 
{
	int T;
	cin >> T;
	
	while(T--)
	{
	    string S;
	    cin >> S;
	    Solution obj;
            char ans = obj.nonrepeatingCharacter(S);
        
            if(ans != '$')
	        cout << ans;
            else 
                cout << "-1";
            
            cout << endl;
	    
	}
	return 0;
}

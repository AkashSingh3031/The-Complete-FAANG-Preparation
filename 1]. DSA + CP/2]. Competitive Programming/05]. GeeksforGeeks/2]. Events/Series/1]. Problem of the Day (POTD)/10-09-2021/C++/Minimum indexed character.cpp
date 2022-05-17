#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        int arr[256];
        for(int i=0;i<256;i++)
            arr[i]=-1;          //initialize the arr like this
        int m=patt.length();
        int n=str.length();
        
        for(int i=0;i<n;i++)
            if(arr[str[i]]==-1)
                arr[str[i]]=i;
         
        int min=INT_MAX;
        for(int j=0;j<m;j++)
            if(arr[patt[j]]!=-1)
                if(arr[patt[j]]<min)
                    min=arr[patt[j]];
         
        if(min==INT_MAX)
            return -1;
        return min;
    }
};

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

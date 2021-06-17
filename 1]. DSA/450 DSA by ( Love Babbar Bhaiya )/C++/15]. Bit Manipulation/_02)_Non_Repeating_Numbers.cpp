//Link : https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
/*
Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers.


Example 1:

Input: 
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output:
3 4 
Explanation:
3 and 4 occur exactly once.*/
#include<bits/stdc++.h>
using namespace std;
 

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int res=0;
        vector <int> vec,v;
        for(int i=0;i<nums.size();i++)
        {
            res^=nums[i];
            
        }
        int set_bit_no = res & ~(res-1);
        int temp=res;
            for(int i=0;i<nums.size();i++)
            {
                if((nums[i]& set_bit_no))
                {
                    vec.push_back(nums[i]);
                }
            }
            for(int i=0;i<vec.size();i++)
            {
               temp^=vec[i]; 
            }
            v.push_back(temp);
            res^=temp;
            v.push_back(res);
            sort(v.begin(),v.end());
            return v;
            
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
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
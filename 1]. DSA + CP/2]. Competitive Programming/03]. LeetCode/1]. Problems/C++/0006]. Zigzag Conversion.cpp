/*
Example 1:
    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"

Example 2:
    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
Explanation:
    P     I    N
    A   L S  I G
    Y A   H R
    P     I

Example 3:
    Input: s = "A", numRows = 1
    Output: "A"
*/

class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        vector <string> tmp(numRows);
        int i=0, n=s.size();
        while(i<n){                                      
            for(int j=0;j<numRows && i<n; j++, i++) 
                tmp[j] += s[i]; 
            for(int j=numRows - 2;j>0 && i<n; j--, i++) 
                tmp[j] += s[i];
        }
        for(int j=0;j<numRows; j++) 
            ans += tmp[j];
        return ans;
    }
};
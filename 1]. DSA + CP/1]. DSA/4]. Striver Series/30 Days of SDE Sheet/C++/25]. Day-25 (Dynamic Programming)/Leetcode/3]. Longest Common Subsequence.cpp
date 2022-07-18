class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
    vector<vector<short>> m(a.size() + 1, vector<short>(b.size() + 1));
        for (auto i = 1; i <= a.size(); ++i)
            for (auto j = 1; j <= b.size(); ++j)
                if (a[i - 1] == b[j - 1]) 
                    m[i][j] = m[i - 1][j - 1] + 1;
                else    
                    m[i][j] = max(m[i - 1][j], m[i][j - 1]);
        return m[a.size()][b.size()];
    }
};
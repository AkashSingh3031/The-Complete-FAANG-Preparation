class Solution {
public:
    vector<int> solve(vector<vector<int>>& arr, int num, int n) {
        set<int> ans;
        vector<bool> vis(n);
        vector<int> res;
        queue<int> Q;
        for(int i = 0; i < arr[num].size(); i++) {
            Q.push(arr[num][i]);
        }
        while(Q.size() != 0) {
            int n = Q.front();
            ans.insert(n);
            Q.pop();
            if(vis[n] == false) {
                vis[n] = true;
                for(int i = 0; i < arr[n].size(); i++) {
                    Q.push(arr[n][i]);
                }
            }
        }
        for(auto i : ans) {
            res.push_back(i);
        }
        return res;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> arr(n, vector<int>());
        vector<vector<int>> ans(n, vector<int>());
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            arr[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i < n; i++) {
            ans[i] = solve(arr, i, n);
        }
        return ans;
    }
};

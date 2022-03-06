class Solution {
public:
    int solve(vector<int>& mapping, int num) {
        string ans = "";
        if(num == 0) return mapping[0];
        while(num != 0) {
            ans += to_string(mapping[num % 10]);
            num /= 10;
        }
        reverse(ans.begin(), ans.end());
        long long res = stoi(ans);
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> M;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            M[solve(mapping, nums[i])].push_back(nums[i]);
        }
        for(auto i : M) {
            for(auto j : i.second) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int xr{};
        for(auto num: nums)
            xr = xr^num;
        return xr;
    }
};
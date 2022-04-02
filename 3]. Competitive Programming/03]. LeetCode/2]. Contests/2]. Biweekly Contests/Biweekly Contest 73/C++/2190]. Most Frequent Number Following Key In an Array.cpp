class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int, int> M;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == key) M[nums[i + 1]]++;
        }
        int ans = 0;
        int prevMax = 0;
        for(auto i : M) {
            if(i.second > prevMax) {
                ans = i.first;
                prevMax = i.second;
            }
        }
        return ans;
    }
};

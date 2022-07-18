class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num;
        int ans = 0;
        
        for(int i : nums) {
            num.insert(i);
        }
        
        for(int i : nums) {
            if(!num.count(i-1)) {
                int count = 1;
                while(num.count(i+count)) {
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};

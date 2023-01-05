class Solution {
public:
 
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<int> id(plantTime.size());
        
        iota(id.begin(), id.end(), 0);
        
        sort(id.begin(), id.end(), [&](int i, int j){return growTime[i] > growTime[j]; });
        
        int ans = 0, day = 0;
        for (int i : id) {
            day += plantTime[i];
            ans = max(ans, day + growTime[i]);
        }
        return ans;
    }
};


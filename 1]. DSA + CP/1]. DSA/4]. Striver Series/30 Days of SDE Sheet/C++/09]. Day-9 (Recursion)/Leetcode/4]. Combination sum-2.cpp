class Solution {
public:
    void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num)
    {
        if(target==0)
        {
            res.push_back(local);
            return;
        }
        for(int i = order;i<num.size();i++)
        {
            if(num[i]>target) return;
            if(i&&num[i]==num[i-1]&&i>order) continue;
            local.push_back(num[i]),
            findCombination(res,i+1,target-num[i],local,num);
            local.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        vector<int> local;
        findCombination(res, 0, target, local, candidates);
        return res;
    }
};
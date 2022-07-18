class Solution {
    class TreeNode {
    public:
        TreeNode* next[2];
        TreeNode () {next[0] = nullptr; next[1] = nullptr;};
    };
    TreeNode* buildTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(), *cur;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            cur = root;
            for (int j = 31; j >= 0; j--) {
                int index = ((num >> j) & 1);
                if (cur->next[index] == nullptr)
                    cur->next[index] = new TreeNode();
                cur = cur->next[index];
            }
        }
        return root;
    }
    
    int dfs(TreeNode* root, int x, int limit, int value, int height) {
        if (value > limit) return -1;
        
        if (height == -1) return x^value;
        
        int bit_x = (x >> height) & 1;
        
        if (root->next[1-bit_x] != nullptr) {
            int v = dfs(root->next[1-bit_x], x, limit, (value | ((1-bit_x) << height)), height-1);
            if (v >= 0) return v;
        }
        if (root->next[bit_x] != nullptr) {
            int v = dfs(root->next[bit_x], x, limit, (value | (bit_x << height)), height-1);
            if (v >= 0) return v;
        }
        
        return -1;
    }
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        TreeNode* root = buildTree(nums);
        
        for (const vector<int>& query : queries) {            
            int tmp = dfs(root, query[0], query[1], 0, 31);
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
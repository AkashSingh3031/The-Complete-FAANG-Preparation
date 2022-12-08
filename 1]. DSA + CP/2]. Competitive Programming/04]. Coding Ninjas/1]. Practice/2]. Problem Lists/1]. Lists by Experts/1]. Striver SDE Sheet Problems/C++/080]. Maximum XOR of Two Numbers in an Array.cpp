class TreeNode {
public:
    TreeNode* next[2];
    TreeNode () {next[0] = NULL; next[1] = NULL;};
};
TreeNode* buildTree(vector<int>& nums) {
    TreeNode* root = new TreeNode(), *cur;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        cur = root;
        for (int j = 31; j >= 0; j--) {
            int index = ((num >> j) & 1);
            if (cur->next[index] ==  NULL)
                cur->next[index] = new TreeNode();
            cur = cur->next[index];
        }
    }
    return root;
}

int helper(TreeNode* cur, int num) {
    int res = 0;
    for (int i = 31; i >= 0; i--) {
        int index = ((num >> i) & 1) ? 0 : 1;
        if (cur->next[index]) {
            res <<= 1;
            res |= 1;
            cur = cur->next[index];
        } else {
            res <<= 1;
            res |= 0;
            cur = cur->next[index ? 0 : 1];
        }
    }
    return res;
}
int maximumXor(vector<int> nums)
{
    // Write your code here.  
    int res = 0;
    TreeNode* root = buildTree(nums);
    for (auto i : nums) {
        res = max(res, helper(root, i));
    }
    return res;
}
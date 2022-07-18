class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), l, r; // 'l' is pivot and 'r' is rightmost successor
        
        // find decreasing sequence point
        for(l=n-2; l>=0; l--)
            if(nums[l] < nums[l+1])
                break;
        
        // if all number in sequence in decreasing order
        if(l<0)
            reverse(nums.begin(), nums.end());
        else {
            // find rightmost successor, which greater than pivot number
            for(r=n-1; r>l; r--)
                if(nums[r] > nums[l])
                    break;
            swap(nums[l], nums[r]);
            // reverse the decreasing sequence after swaping pivot number and rightmost successor
            reverse(nums.begin()+l+1, nums.end());
        }
    }
};

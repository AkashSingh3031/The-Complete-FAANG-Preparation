/**
 * @author Mayur Ingle(https://github.com/thecoder8890)
 *Problem :- https://leetcode.com/problems/two-sum/
 */
class Solution {
    public int[] twoSum(int[] nums, int target) {
         int[] ans = new int[2];

        Map<Integer, Integer> map = new HashMap<>();
        for (int i=0;i<nums.length;i++) {
            if (map.containsKey(target - nums[i])) {
                ans[1] = i;
                ans[0] = map.get(target - nums[i]);
                return ans;
            }
            map.put(nums[i], i);
        }
        return ans;
        
    }
}

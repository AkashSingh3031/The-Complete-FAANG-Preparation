/*
'''
2784. Check if Array is Good

You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].

base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n).
For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

Return true if the given array is good, otherwise return false.

Note: A permutation of integers represents an arrangement of these numbers.

Example 1:

Input: nums = [2, 1, 3]
Output: false
Explanation: Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3.
However, base[3] has four elements but array nums has three. Therefore, it can not be a permutation of base[3] = [1, 2, 3, 3]. So the answer is false.
Example 2:

Input: nums = [1, 3, 3, 2]
Output: true
Explanation: Since the maximum element of the array is 3, the only candidate n for which this array could be a permutation of base[n], is n = 3.
It can be seen that nums is a permutation of base[3] = [1, 2, 3, 3] (by swapping the second and fourth elements in nums, we reach base[3]).
Therefore, the answer is true.
Example 3:

Input: nums = [1, 1]
Output: true
Explanation: Since the maximum element of the array is 1, the only candidate n for which this array could be a permutation of base[n], is n = 1.
It can be seen that nums is a permutation of base[1] = [1, 1]. Therefore, the answer is true.
Example 4:

Input: nums = [3, 4, 4, 1, 2, 1]
Output: false
Explanation: Since the maximum element of the array is 4, the only candidate n for which this array could be a permutation of base[n], is n = 4.
 However, base[4] has five elements but array nums has six. Therefore, it can not be a permutation of base[4] = [1, 2, 3, 4, 4]. So the answer is false.
'''
*/

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        int size = nums.size();
        int last = nums[size - 1];

        if (last + 1 != size)
            return false;

        unordered_map<int, int> map;

        for (int i = 1; i < last + 1; i++)
            map[i] = 0;

        for (auto x : nums)
            map[x]++;

        for (auto x : map)
            cout << x.first << " " << x.second << endl;

        auto it = min_element(begin(map), end(map), [](const auto &l, const auto &r)
                              { return l.second < r.second; });

        if (map[last] == 2 && it->second > 0)
            return true;
        return false;
    }
};


//
class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        if (maxi + 1 != n)
            return 0;
        int cnt = 0, count = 0;
        for (auto it : nums)
            if (it == maxi)
                cnt++;
        if (cnt != 2)
            return 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                count++;
            if (count > 1)
                return 0;
        }
        return 1;
    }
};
/*
Example 1:
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
    Input: height = [1,1]
    Output: 1
*/

class Solution 
{
  public:
    int maxArea(vector<int>& height) 
    {
        int left = 0, right = height.size()-1;
        int max_area = (right-left)*min(height[left], height[right]);
        while(left < right)
        {
            if(height[left] < height[right])
                left++;
            else
                right--;
            max_area = max(max_area, (right-left)*min(height[left], height[right]));
        }
        return max_area;
    }
};

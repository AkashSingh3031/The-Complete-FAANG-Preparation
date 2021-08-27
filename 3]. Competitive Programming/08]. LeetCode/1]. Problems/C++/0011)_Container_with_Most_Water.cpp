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

/*
Example 1:
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
    Input: height = [1,1]
    Output: 1
*/

class Solution {
public:
    int maxArea(vector<int>& h) 
    {
        int res=0;
        int x=0;
        int y=(int)h.size();
        y--;
        while(x<y)
        {
            int cur=min(h[x],h[y])*(y-x);
            res=max(res,cur);
            if(h[x]<=h[y])
                x++;
            else
                y--;
        }
        return res;
    }
};

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

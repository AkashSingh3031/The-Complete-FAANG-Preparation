/*
Example 1:
  Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
  Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.

Example 2:
  Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
  Output: false
Explanation: Because there is a gap between the two rectangular regions.

Example 3:
  Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
  Output: false
Explanation: Because two of the rectangles overlap with each other.
*/

class Solution {
    long hash(long x, long y) {
        return (x + 1e5) * (2e5 + 1) + (y + 1e5);
    }
    int update(int s, int bc, int bn0, int bn1) {
        if (s & bn0)
            s -= bn0;
        else if (s & bn1)
            s -= bn1;
        else 
          s |= bc;
        return s;
    }
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<long, int> corners;
        for (auto& rect: rectangles) {
            long bl = hash(rect[0], rect[1]),
                 br = hash(rect[2], rect[1]),
                 tr = hash(rect[2], rect[3]),
                 tl = hash(rect[0], rect[3]);
            
            if (corners[bl] & 1 || corners[br] & 2 || corners[tr] & 4 || corners[tl] & 8)
                return false;
            
            if (!(corners[bl] = update(corners[bl], 1, 8, 2)))
                corners.erase(bl);
            if (!(corners[br] = update(corners[br], 2, 1, 4)))
                corners.erase(br);
            if (!(corners[tr] = update(corners[tr], 4, 2, 8)))
                corners.erase(tr);
            if (!(corners[tl] = update(corners[tl], 8, 4, 1)))
                corners.erase(tl);
        }
        return corners.size() == 4;
    }
};

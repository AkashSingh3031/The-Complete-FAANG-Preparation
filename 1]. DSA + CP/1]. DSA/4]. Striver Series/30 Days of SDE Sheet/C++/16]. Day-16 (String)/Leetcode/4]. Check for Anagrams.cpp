class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s == t)
            return true;
        if(s.size() != t.size())
            return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s == t)
            return true;
        return false;
    }
};
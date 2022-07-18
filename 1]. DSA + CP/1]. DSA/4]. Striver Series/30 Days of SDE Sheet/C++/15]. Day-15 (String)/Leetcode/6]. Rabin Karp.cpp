class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string as = a;
        for (int rep = 1; rep <= b.length() / a.length() + 2; rep++, as += a)
            if (as.find(b) != string::npos) 
                return rep;
        return -1;
    }
};
class Solution {
    void trim(string& s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
    }
public:
    int myAtoi(string s) {
        trim(s);
        const int sign = s[0] == '-' ? -1 : 1;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        long num = 0;

        for (const char c : s) {
            if (!isdigit(c))
                break;
            num = num * 10 + (c - '0');
            if (sign * num < INT_MIN)
                return INT_MIN;
            if (sign * num > INT_MAX)
                return INT_MAX;
        }

        return sign * num;
    }

    int strStr(string haystack, string needle) {
        if(haystack.find(needle) < haystack.size())
            return haystack.find(needle);
        else
            return -1;
    }
};
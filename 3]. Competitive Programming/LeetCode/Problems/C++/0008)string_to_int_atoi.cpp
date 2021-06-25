#include <bits/stdc++.h>  
#include <string>
#include <algorithm>
class Solution {
public:
    
    string trim(string s)
    {
        string white = " ";
        int pos = 0;
        while (s[pos] == ' ')
        {
            ++pos;
        }
        return s.substr(pos, s.size() - pos);
    }
    string trimZero(string s)
    {
        int pos = 0;
         while (s[pos] == '0')
        {
            ++pos;
        }
        return s.substr(pos, s.size() - pos);
    }
    char sign = ' ';
    int myAtoi(string s) {
        s = trim(s);
        if (s[0] == '-' or s[0] == '+')
        {
             sign = s[0];
            s = s.substr(1, s.size() - 1);
        }
        s = trimZero(s);
        int i = 0;
        long long num = 0;
        long long prod = 1;
        bool trailZero = true;
       
        while(isdigit(s[i]))
        {
            if ((prod * 10) > INT32_MAX)
            {
                if (sign == '-')
                    return INT32_MIN;
                else
                    return INT32_MAX;
            }
            if (i != 0)
                prod *= 10;
            ++i;
        }
        
      //  cout << prod << endl;
        i = 0;
        while (isdigit(s[i]))
        {
           
                num += (s[i] - '0')*prod;
                prod = prod / 10;
            
           
            ++i;
        }
    int x;
    if (sign == '-')
    {
        x = INT32_MIN < -1*num? -1*num: INT32_MIN;
        return x;
    }
    else
        x = INT32_MAX < num? INT32_MAX: num;
        return x;
    }
    
    
};
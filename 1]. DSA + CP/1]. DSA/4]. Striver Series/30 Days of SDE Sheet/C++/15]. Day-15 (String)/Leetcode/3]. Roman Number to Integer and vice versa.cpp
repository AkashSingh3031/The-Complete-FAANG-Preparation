class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
       int sum = T[s.back()];
       for (int i = s.length() - 2; i >= 0; --i) 
       {
           if (T[s[i]] < T[s[i + 1]])
                sum -= T[s[i]];
           
           else
                sum += T[s[i]];
           
       }

       return sum;
    }

    string intToRoman(int num) {
        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        for(int i=0; num != 0; i++) {
            while(num >= val[i]) {
                num -= val[i];
                res += sym[i];
            }
        }
        return res;
    }
};
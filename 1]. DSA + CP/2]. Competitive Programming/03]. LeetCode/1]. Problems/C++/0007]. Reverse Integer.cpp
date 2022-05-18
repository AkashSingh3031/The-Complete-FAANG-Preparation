/*
Example 1:
    Input: x = 123
    Output: 321

Example 2:
    Input: x = -123
    Output: -321

Example 3:
    Input: x = 120
    Output: 21
*/

class Solution {
public:
    int reverse(int x) {
        long long a=0;
        while(x) {
            a = x%10 + a*10;
            x /= 10;
        }
        return (a > INT_MAX || a < INT_MIN) ? 0 : a;
    }
};
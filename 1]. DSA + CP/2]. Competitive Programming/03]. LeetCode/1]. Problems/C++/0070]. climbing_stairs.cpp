/*
'''
70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
'''
*/

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;

        int c1 = 0, c2 = 1;
        while (n > 0)
        {
            n--;
            int temp = c1;
            c1 = c2;
            c2 = c1 + temp;
        }
        return c2;
    }
};
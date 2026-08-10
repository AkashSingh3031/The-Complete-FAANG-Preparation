/*
231. Power of Two

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.
*/

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 1 or n == 2)
            return true;
        long long int i = 2;
        while (1)
        {
            if (i * 2 == n)
                return true;
            else if (i * 2 > n)
                return false;
            else
                i = i * 2;
            cout << i << endl;
        }
    }
};

//best
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 1 || n == 2)
            return true;
        if (n == 0 || n == INT_MIN)
            return false;
        if (n & (n - 1))
            return false;
        return true;
    }
};
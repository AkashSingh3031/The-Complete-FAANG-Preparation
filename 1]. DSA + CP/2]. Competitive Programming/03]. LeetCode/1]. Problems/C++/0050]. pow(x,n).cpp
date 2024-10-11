/*
50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

class Solution
{
public:
    double myPow(double x, int n)
    {
        return pow(x, n);
    }
};




//

class Solution
{
public:
    double myPower(double x, long long N)
    {
        if (N == 0)
            return 1.0;
        double y = myPower(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n)
    {
        long long N = n;
        return N >= 0 ? myPower(x, N) : 1.0 / myPower(x, -N);
    }
};


//fast
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
        {
            n = abs(n);
            x = 1 / x;
        }
        if (n % 2 == 0)
            return myPow(x * x, n / 2);
        else
            return x * myPow(x, n - 1);
    }
};
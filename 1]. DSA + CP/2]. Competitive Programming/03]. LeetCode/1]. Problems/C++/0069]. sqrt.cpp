/*
'''
69. Sqrt(x)

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
'''
*/

class Solution
{
public:
    int mySqrt(int x)
    {
        double i = 0;
        while (i * i <= x)
        {
            if ((i * i) <= x && (i + 1) * (i + 1) > x)
                return int(i);
            i++;
        }
        return 0;
    }
};

//
class Solution
{
public:
    int mySqrt(int num)
    {
        if (num <= 1) // square root of 0 is 0, square root of 1 is 1, square root of a negative is an imaginary.
            return num;

        double tolerance = 1e-7;

        double x0 = num;
        double x = x0 - (x0 * x0 - num) / (2 * x0);

        while (abs(x - x0) > tolerance)
        {
            x0 = x;
            x = x0 - (x0 * x0 - num) / (2 * x0);
        }

        return (int)x;
    }
};
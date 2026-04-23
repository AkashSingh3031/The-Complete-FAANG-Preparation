/*
'''
66. Plus One

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
'''
*/

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        long long num = 0;
        for (auto i : digits)
            num = num * 10 + i;
        num++;
        digits.clear();
        while (num)
        {
            int n = num % 10;
            digits.emplace(begin(digits), n);
            num /= 10;
        }
        cout << num;
        return digits;
    }
};


//
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int sz = digits.size() - 1;
        cout << sz;
        /*if (sz==0 && digits[sz]==9)
            {
                digits[sz] = 0;
                digits.emplace(digits.begin(), 1);
                return digits;
            }
        else if (sz==0)
            {
                int n=digits[sz];
                digits[sz] = n+1;
                return digits;
            }*/
        while (sz >= 0)
        {

            if (digits[sz] <= 8)
            {
                int n = digits[sz];
                digits[sz] = n + 1;
                break;
            }
            else
            {
                digits[sz] = 0;
                sz--;
            }
            if (sz == -1)
            {
                digits.emplace(digits.begin(), 1);
            }
        }
        return digits;
    }
};

//
class Solution
{
public:
    vector<int> plusOne(vector<int> &v)
    {
        int n = v.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                v[i]++;
            if (v[i] == 10)
            {
                v[i] = 0;
                if (i != 0)
                {
                    v[i - 1]++;
                }
                else
                {
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        return v;
    }
};

//
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                digits[i]++;
            }
            if (digits[i] == 10)
            {
                digits[i] = 0;
                if (i != 0)
                {
                    digits[i - 1] += 1;
                }
                else
                {
                    digits.insert(digits.begin(), 1);
                }
            }
        }
        return digits;
    }
};
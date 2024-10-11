/*
860. Lemonade Change

At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills).
Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change,
or false otherwise.
*/

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        if (bills[0] == 10 || bills[0] == 20 || bills[1] == 20)
            return false;

        unordered_map<int, int> m;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                m[5]++;
            }
            else if (bills[i] == 10)
            {
                m[10]++;
                if (bills[i] >= 1)
                {
                    m[5]--;
                }
                else
                    return false;
            }
            else if (bills[i] == 20)
            {
                m[20]++;
                if (m[10] >= 1 && m[5] >= 1)
                {
                    m[10]--;
                    m[5]--;
                    continue;
                }
                else if (m[5] >= 3)
                {
                    m[5]--;
                    m[5]--;
                    m[5]--;
                }
                else
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};

/*
    Time Complexity: O( N )
    Space Complexity: O( 1 )

    where 'N' is the length of string T.
*/


char whoWins(string T)
{


    char ans = 'D';
    int cntOdd = 0 , cntEven = 0;

    // Iterate over all digits of 'T'.

    for (auto i : T)
    {

        // increase counter if 'i' is odd.
        if ((i - '0') % 2)
        {
            cntOdd++;
        }
        // else increase even counter.
        else
        {

            cntEven++;
        }
    }

    if (cntEven > cntOdd)
    {

        // Update the 'ans' if the counter of the even digit is greater than the counter of the odd digit.
        ans = 'K';
    }
    else if (cntEven < cntOdd)
    {
        // Update the 'ans' if the counter of the even digit is less than the counter of the odd digit.

        ans = 'T';
    }


    return ans;
}
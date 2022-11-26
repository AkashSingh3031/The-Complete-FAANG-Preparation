/*
    Time Complexity : O( 1 )
    Space Complexity : O( 1 )
    
    where '1' represents constant. 
*/

int equalHappy(int n, int m)
{
    // 'REM' stores the remainder.
    int rem = m % n;

    // If 'REM' is '0' return '1'.
    if (rem == 0) {
        return 1;
    }

    // Else return '0'.
    return 0;
}
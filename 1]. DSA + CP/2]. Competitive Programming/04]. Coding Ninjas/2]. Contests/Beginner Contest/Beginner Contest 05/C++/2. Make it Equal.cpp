/*
    Time Complexity: O(1).
    Space Complexity: O(1).

*/

int makeItEqual(int X, int Y)
{

    // Checking if both 'X' and 'Y' are same or not.
    if (X == Y)
    {
        return 0;
    }

    // Checking if we can make 'X' and 'Y' equal if we select 'Z' = 'X - Y'.
    else if (X > Y && (X - Y) % 2 == 0)
    {
        return 1;
    }

    // Checking if we can make 'X' and 'Y' equal if we select 'Z' = 'Y - X'.
    else if (X < Y && (Y - X) % 2 == 1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
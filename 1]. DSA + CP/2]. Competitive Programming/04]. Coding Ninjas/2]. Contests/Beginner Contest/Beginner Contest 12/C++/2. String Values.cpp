/*
    Time Complexity: O(1)
    Space Complexity: O(1)

*/
string solution(long long N, long long X)
{
    // Checking if X is between the range of sum of values which the string of size can have.
    if (N <= X && 26ll * N >= X) {
        return "YES";
    }
    else {
        return "NO";
    }
}
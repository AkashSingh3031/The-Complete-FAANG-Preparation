/*
    Time Complexity: O(sqrt(N))
    Space Complexity: O(1)

    Where 'N' is the input.
*/


int maximumSquareDivisor(int n) {
    int answer = 1;

    // Storing the copy of 'n'.
    int nCopy = n;

    // Iterating over all possible factors from 2 to sqrt('n').
    for (long fact = 2; fact * fact <= n; fact++) {

        // 'count' determines frequency of 'fact'.
        int count = 0;

        while (nCopy % fact == 0) {
            count++;

            // If 'fact' divides 'nCopy' twice then include it once in our 'answer'.
            if (count == 2) {
                answer *= fact;

                // Update the frequency to '0'.
                count = 0;
            }

            // Remove the fact from 'nCopy'.
            nCopy /= fact;
        }
    }

    // Return 'answer'  here.
    return answer;
}
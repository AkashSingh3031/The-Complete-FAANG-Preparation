/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the size of the array.
*/

vector<int> zeroPermutation(vector<int> &array) {

    int n = array.size();

    int position[n + 1];

    // Map each element with its position in the array.
    for (int i = 0; i < n; i++) {
        position[array[i]] = i;
    }

    // Get the sum of the array.
    int sum = (n * (n + 1)) / 2;

    // If sum of array is odd it is impossible.
    if (sum % 2 == 1) {
        return array;
    }

    // Else it is always possible.
    int currentNum = n;

    // For making 'sum' == 0 , positive elements sums upto '(sum/2)'.
    // And negative elements sums upto '(sum/2)'.
    int targetSum = sum / 2;
    while (targetSum) {

        // If targetSum is greater than or equal to the 'currentNum' element.
        // We will perform an operation on that element.
        if (targetSum >= currentNum) {
            int ind = position[currentNum];
            array[ind] *= -1;
            targetSum -= currentNum;
        }
        currentNum--;
    }

    // Return array after all operations here.
    return array;
}
/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the size of the array.
*/

int gap(vector < int > & v) {
    // Here 'sum' will store the sum of the marks of all the students.
    int sum = 0, n = v.size();

    for (int i = 0; i < n; i++) {
        sum += v[i];
    }

    // If the sum of the marks of all the students can be evenly divided among all the students then return 0, else return 1.
    if (sum % n == 0) {
        return 0;
    } else {
        return 1;
    }
}
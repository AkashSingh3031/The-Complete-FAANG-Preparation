/*
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

int freeVertices(int n, int m){

    // If m==0 then our answer is n.
    if (m == 0){
        return n;
    }

    // Calculating our answer.
    int ans = n - ceil((1 + sqrt(1 + 8 * m)) / 2);

    // We are returning the answer here.
    return ans;
}
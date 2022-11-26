/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the length of the array.
*/

int mex(vector < int > v, int k) {

    // Here 'n' is the size of the vector.
    int n = v.size();

    // Here 'sz' represents the size of the Hash Table named as 'mp'.
    int sz = max(n, k);
    vector < int > mp(sz, 0);

    // Now we will hash the remainder of all the elements with 'k'.
    for (int i = 0; i < n; i++) {
        mp[v[i] % k]++;
    }

    // Now we will try to make all the numbers from '0' to 'N'.
    for (int i = 0; i < n; i++) {

        // In order to generate 'i' we need the element having modulo value equals to 'need'.
        int need = i % k;

        // If there is no such element, then we can't form 'i' and will return the 'i' as the answer.
        if (mp[need] == 0) {
            return i;
        }

        // Else we will use this number to generate 'i'.
        mp[need]--;
    }

    return n;
}
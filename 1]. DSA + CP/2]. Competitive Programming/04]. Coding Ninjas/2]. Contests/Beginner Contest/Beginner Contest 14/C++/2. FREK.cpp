/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the size of the array.
*/

int FREK(vector < int > & v) {
    
    // Here 'n' represents the size of the given vector 'v'.
    int n = v.size();

    // Map 'mp' will be used to store the frequency of each element.
    unordered_map < int, int > mp;
    for (int i = 0; i < n; i++) {
        mp[v[i]]++;
    }

    // Here, 'element' will store the maximum occurring number, and 'ma' will store the frequency of the maximum occurring element. 
    int ma = -1, element = INT_MAX;

    for (auto x: mp) {
        if (x.second > ma) {
            ma = x.second;
        }
    }

    for (auto x: mp) {
        if (x.second == ma) {
            element = min(element, x.first);
        }
    }
    // Here, 'l' and 'r' will store the leftmost and rightmost index of the most occurring number 'element.' 
    int l = -1, r = -1;

    // Here we will find the leftmost index.
    for (int i = 0; i < n; i++) {
        if (v[i] == element) {
            l = i;
            break;
        }
    }

    // Here we will find the rightmost index.
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == element) {
            r = i;
            break;
        }
    }

    // In the end return the ans.
    return n - (r - l + 1);

}
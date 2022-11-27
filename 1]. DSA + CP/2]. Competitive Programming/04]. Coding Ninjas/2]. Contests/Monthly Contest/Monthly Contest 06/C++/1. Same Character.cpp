/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(N)

    where 'N' is the length of the string.
*/

int sameCharacter(string s){
    int n = s.size();

    // Storing 's' into another string 'a'.
    string a = s;

    // Sorting the string 'a'.
    sort(a.begin(), a.end());

    // Calculating our answer.
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == a[i]){
            ans++;
        }
    }

    // We are returning the answer.
    return ans;
}
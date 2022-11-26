/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' denotes the length of the string 'S'.
*/


int goodnessScore(string s) {

    // 'upp' stores the frequency of uppercase letters and 'low' stores the frequency of lowercase letters.
    vector<int> upp(26), low(26);

    // Iterate over the string 's'.
    for (char c: s) {

        // If the character is uppercase.
        if (c >= 'A' && c <= 'Z') {

            // Increase the frequency of that character.
            upp[c - 'A']++;
        }else{

            // Decrease the frequency of that character.
            low[c - 'a']++;
        }
    }

    // 'goodness' stores the goodness score of the string 's'.
    int goodness = 0;

    // Iterate over all the positions.
    for (int i = 0; i < 26; ++i) {

        // If the frequency of uppercase letter is more than the lowercase letter.
        if (upp[i] > low[i]) {

            // Increase the goodness score by 1.
            goodness++;
        }else if (upp[i] < low[i]) {
            // Decrease the goodness score by 1.
            goodness--;
        }
    }
    return goodness;
}

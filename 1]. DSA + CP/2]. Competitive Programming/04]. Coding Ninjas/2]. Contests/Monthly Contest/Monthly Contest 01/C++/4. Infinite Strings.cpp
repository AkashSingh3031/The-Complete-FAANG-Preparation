/*
    Time Complexity : O(max(|S|, |T|))
    Space Complexity : O(|S|)

    Where N is the number of the strings and '|S|' is the length of a string.
*/


#include <cstring>

int infiniteStrings(string s, string t){
    // Initialize a variable 'lens' as the length of string 'S'.
    int lens = s.size();
    
    // Initialize a variable 'lent' as the length of string 'T'.
    int lent = t.size();

    int allChar[26];
    for(int i = 0; i < 26; i++){
        allChar[i] = -1;
    }

    // Marking all the character present in 'S' as present.
    for(int i = 0; i < lens; i++){
        if(allChar[s[i] - 'a'] == -1){
            allChar[s[i] - 'a'] = i + 1;
        }
    }

    // Checking if we can make the string 'T' or not.
    for(int i = 0; i < lent; i++){
        if(allChar[t[i] - 'a'] == -1){
            return -1;
        }
    }

    // Initializing a 2D array to get next character from current position.
    int nextChar[lens + 1][26];
    memset(nextChar, -1, sizeof(nextChar));

    // Filling 2D array 'nextChar'.
    for(int i = lens - 1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            nextChar[i + 1][j] = allChar[j];
            allChar[j]++;
        }

        allChar[s[i] - 'a'] = 1;
    }

    int ans = 0;
    int index = lens;

    // For all the characters in string 'T'.
    for(int i = 0; i < lent; i++){
        int temp = nextChar[index][t[i] - 'a'];
        
        ans += temp;
        index = 1 + (index + temp - 1) % lens;
    }

    // Returning the final answer.
    return ans;
}

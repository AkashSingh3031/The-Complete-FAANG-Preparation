/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the size of the string.
*/

string stringOperation(string &s, int k){
    int n = s.size();

    // Creating array 'occ' to store the occurrences of characters of string.
    int occ[26] = {0};

    // Storing the occurances of the characters.
    for (int i = 0; i < n; i++){
        occ[s[i] - 'a']++;
    }

    // Pushing vowels into vector so that we can check for all vowels.
    vector<char> v;
    v.push_back('a');
    v.push_back('e');
    v.push_back('i');
    v.push_back('o');
    v.push_back('u');

    // Creating variable 'flag' to store our answer.
    int flag = 0;

    // Checking, if we can make the characters of the string same and all character vowel.
    for (auto ch : v){
        int x = occ[ch - 'a'];
        if (n - x == k)
        {
            flag = 1;
        }
    }

    // We are returning our answer here.
    if (flag == 1){
        return "YES";
    }else{
        return "NO";
    }
}
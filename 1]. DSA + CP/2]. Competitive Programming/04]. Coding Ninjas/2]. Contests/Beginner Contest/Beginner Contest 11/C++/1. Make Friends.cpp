
/*
    Time Complexity: O( N + M )
    Space Complexity: O( 1 )

    where 'M' and N' are the length of string s1 and s2 respectively.
*/


string IsFriend(string s1, string s2)
{
     

    vector<bool> ck(26, false);
    for (int i = 0; i < s1.size(); i++)
    {
        // Mark character s1[i] as present in ck vector.
        ck[s1[i] - 'a'] = true;
    }

    for (int i = 0; i < s2.size(); i++)
    {
        // To check if character s2[i] is present in s1.
        if (ck[s2[i] - 'a'])
        {
            
            return "Yes";
        }
    }


    // None of the common character are found.
    return "No";
}
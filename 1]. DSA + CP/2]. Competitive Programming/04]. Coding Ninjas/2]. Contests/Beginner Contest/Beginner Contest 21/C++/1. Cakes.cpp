/* 
    Time Complexity: O(N).
    Space Complexity: O(1).
    Where 'N' is the number of cakes.
*/

#include <iostream>
#include <algorithm>
using namespace std;
long long int noOfCakes(int n, vector<string> &s)
{
    //Initialize a vector 'freq' of 64-bit integers to store the frequency of cakes.
    vector<long long> freq(5);

    //Iterate from 'i' = 0 to 'N'-1.
    for(int i = 0 ; i < n; i++) {

        //If the first letter of 'i'th cake is 'c'.
        if (s[i][0] == 'c')
            
            //Increment 'freq[0]' by 1.
            freq[0]++;

        //If the first letter of 'i'th cake is 'a'.
        else if (s[i][0] == 'a')

            //Increment 'freq[1]' by 1.
            freq[1]++;

        //If the first letter of 'i'th cake is 'k'.
        else if (s[i][0] == 'k')

            //Increment 'freq[2]' by 1.
            freq[2]++;

        //If the first letter of 'i'th cake is 'e'.
        else if (s[i][0] == 'e')

            //Increment 'freq[3]' by 1.
            freq[3]++;

        //If the first letter of 'i'th cake is 's'.
        else if (s[i][0] == 's')

            //Increment 'freq[4]' by 1.
            freq[4]++;
    }

    //Initialize an integer 'ans' to store the answer.
    long long ans = 0;

    //Iterate from 'i' = 0 to 3.
    for(int i = 0; i < 3; i++) {

        //Iterate from 'j' = 'i + 1' to 4.
        for(int j = i + 1; j < 4; j++) {

            //Iterate from 'k' = 'j + 1' to 5.
            for(int k = j + 1; k < 5; k++) {

                //Increment ans by freq[i] * freq[j] * freq[k].
                ans += freq[i] * freq[j] * freq[k];
            }
        }
    }

    //Return ans.
    return ans;
}


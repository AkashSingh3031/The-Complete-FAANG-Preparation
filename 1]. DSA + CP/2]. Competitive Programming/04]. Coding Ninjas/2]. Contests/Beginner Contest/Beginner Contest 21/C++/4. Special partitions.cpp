/* 
    Time Complexity: O(N * K)
    Space Complexity: O(1)
    where 'N' is the number of characters in 'S' and 'K' is the length of each partition.
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

// Checking if the string is palindrome.
bool isPalindrome(string s) {
    int i = 0, j = (int)s.size() - 1;

    //check if elements at same distance from both sides are equal or not.
    while(i < j) {

        //If elements both both side are not equal 
        if(s[i++] != s[j--]) {

            //Return false.
            return false;
        }
    }

    //Return true.
    return true;
}
int specialCount(int n, int x, int k, string &s) {

    //Initialize an integer variable 'count' = 0 to store the number of special substrings.
    int count = 0;

    // Iterate from 'i' = 0 to 'i' = 'K - 1.
    for(int i = 0; i < k; i++){

        //Initialize integer variable 'left' = 'i' and 'right' = 'i' to denote the left and right pointers respectively.
        int left = i;
        int right = i;

        //Initialize integer variable 'currentPartitions' = 0 to store the number of palindromic partitions.
        int currentPartitions = 0;

        //Run a while loop with the condition 'right' less than 'N'.
        while(right < n) {

            // If 'right + K - 1' is greater than equal to 'N' then break.
            if(right + k - 1 >= n) {
               break;
            } 

            //If substring starting at the index 'right' and of length 'K' is a palindrome.
            if(isPalindrome(s.substr(right, k))) {

                //Increment 'currentPartitions'.
                currentPartitions++;
                right += k;
            }
            else {

                //Update 'currentPartitions' to 0.
                currentPartitions = 0;

                //Update 'left' and 'right' to 'right + K'.
                left = right = right + k;
            }

            //If 'currentPartitons' are greater than 'X'.
            if(currentPartitions > x) {

                //Increment 'left' by 'K'.
                left += k;

                //Decrement 'currentPartitons'.
                currentPartitions--;
            }

            //If 'currentPartitions' is equal to 'X'.

            if(currentPartitions == x) {

                //Increment 'count'.
                count++;
            }

        }
    }

    // Return 'count'.
    return count;

}
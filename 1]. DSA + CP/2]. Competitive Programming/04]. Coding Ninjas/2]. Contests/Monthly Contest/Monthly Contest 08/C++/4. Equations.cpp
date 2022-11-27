/* 
    Time complexity: O(T * log(max(K, M)))
    Space complexity: O(1).
    where 'T' is the number of test cases and 'K' is the initial length, and 'M' is the final length.
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int solveEquations(int k, int m)
{

    //If 'K' is greater than 'M', then swap 'K' and 'M'.
    if (k > m) {
        swap(k, m);
    }

    //Initialize three integer variables 'a', 'b', and 'c' to 'K' to store the sides of the triangle.
    long long a = k, b = k, c = k;

    //Initialize an integer variable 'ans' = 0, to store the answer.
    int ans = 0;

    //Run a while loop with condition 'true'.
    while (true) {

        //If all three sides are greater than 'M'.
        if (a >= m && b >= m && c >= m) {

            //Return 'ans'.
            return ans;
        }

        //If 'a' is the smallest side.
        if (ans % 3 == 0) {

            //update 'a' to 'b + c - 1'.
            a = b + c - 1;

            //Increment 'ans'.
            ans++;
        }

        //If 'b' is the smallest side.
        else if (ans % 3 == 1) {

            //update 'b' to 'a + c - 1'.
            b = a + c - 1;

            //Increment 'ans'.
            ans++;
        }

        //If 'c' is the smallest side.
        else {

            //update 'c' to 'a + b - 1'.
            c = a + b - 1;

            //Increment 'ans'.
            ans++;
        }
    }

    //Return ans.
    return ans;
}

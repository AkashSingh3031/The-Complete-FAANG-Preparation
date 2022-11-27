/*
    Time Complexity : O(N).
    Space Complexity: O(N).
    Where 'N' is the number of elements in the cool sequence.
*/ 

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> coolsequences(int n)
{
    //Declare an unordered set of integer type 'vec' to store the sequence.
    unordered_set<int> vec;

    //If 'N' == 3, update 'vec' to {2, 5, 63}.
    if (n == 3) {
        vec = {2, 5, 63};
    }

    //Else if 'N' == 4, update 'vec' to {2, 3, 9, 10}.
    else if (n == 4) {
        vec = {2, 3, 9, 10};
    }

    //Else if 'N' == 5, update 'vec' to {2, 3, 6, 9, 10}.

    else if (n == 5) {
        vec = {2, 3, 6, 9, 10};
    }
    else {

        //Initialize an integer 'current' to 0 to store the numbers to be inserted.
        int current = 0;

        //Initialize an integer 'sum' to 0 to store the sum of the sequence.
        int sum = 0;

        //Iterate from 'i' = 0 to 'N'.
        for (int i = 0; i < n; i++)
        {
            //If 'current % 6' is equal to 0, increment 'current' by 2.
            if (current % 6 == 0) {
                current += 2;
            }

            //Else if 'current % 6' is equal to 2 increment 'current' by 1.
            else if (current % 6 == 2) {
                current++;
            } 

            //Else if 'current % 6' is equal to 3 increment 'current' by 1.
            else if (current % 6 == 3) {
                current++;
            }
            //Else increment 'current' by 2.
            else {
                current += 2;
            } 
            
            //Insert 'current' into 'vec'.
            vec.insert(current);

            //Update 'sum' by 'current'.
            sum += current;
        }
        current++;

        //If 'sum % 6' is equal to 2
        if (sum % 6 == 2)
        {
            //Erase '8' from 'vec'.
            vec.erase(8);

            //Run a while loop until 'current' is not divisible by 6.
            while (current % 6 != 0) {

                //Increment 'current' by 1.
                current++;
            }

            //Insert 'current' into 'vec'.
            vec.insert(current);
        }

        //Else if 'sum % 6' is equal to 3.
        else if (sum % 6 == 3)
        {
            //Erase '9' from 'vec'.
            vec.erase(9);

            //Run a while loop until 'current' is not divisible by 6.
            while (current % 6 != 0) {
                current++;
            }

            //Insert 'current' into 'vec'.
            vec.insert(current);
        }

        //If 'sum % 6' is equal to 5.
        else if (sum % 6 == 5)
        {
            //Erase '9' from 'vec'.
            vec.erase(9);

            //Run a while loop until 'current % 6' is not equal to 4.
            while (current % 6 != 4) {
                current++;
            } 

            //Insert 'current' into 'vec'.
            vec.insert(current);
        }
    }

    //Declare a vector 'ans' to store the answer.
    vector<int> ans;

    //Iterate from it = 'vec.begin()' to 'vec.end()'.
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        //Insert the current element into 'ans'.
        ans.push_back(*it);
    }

    //Return 'ans'.
    return ans;
}
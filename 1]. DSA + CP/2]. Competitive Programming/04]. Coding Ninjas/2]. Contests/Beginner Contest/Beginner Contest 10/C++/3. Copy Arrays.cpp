/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' denotes the length of the array 'Arr'.
*/

#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> &arr) {
    
    // Declaring a variable in order to store the length of 'arr'.
    int n = arr.size();

    // Declaring the HashMap 'x'.
    unordered_map<int, int> x;

    // Declaring 'ans' variable for storing the result.
    int ans = 0;

    for(int i = 0; i < n; i++) {

        // Increasing the frequency of elements on every iteration.
        x[arr[i]]++;

        // Whenever the frequency of any element becomes greater than 1, the subarray can be called a copy array.
        if(x[arr[i]] > 1) {

            // Incrementing the ans variable as a copy array is discovered.
            ans++;
            
            // Clearing the Hashmap in order to store frequency for the new subarray from next iteration.
            x.clear();  
        }
    }
    
    return ans;
}
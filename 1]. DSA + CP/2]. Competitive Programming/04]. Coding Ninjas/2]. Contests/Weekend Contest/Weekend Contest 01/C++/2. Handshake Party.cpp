/*
    Time Complexity: O(n*log(n)).
    Space Complexity: O(1).

    where n is the number of guests.
*/


#include<algorithm>

int maximumHandshakes(int n, vector<int> &entry, vector<int> &exit){

    int MOD = 1e9 + 7;

    // Sorting both entry and exit times.
    sort(entry.begin(), entry.end());
    sort(exit.begin(), exit.end());

    int i = 0 , j = 0, currentPerson = 0, maximumPerson = 0;

    // Iterating over all the guests.
    while(i < n){

        // If current entry time is less than the current exit
        // time, incease the currentPerson by 1 and increase 'i'.
        while(i < n && entry[i] < exit[j]){
            i++;
            currentPerson++;
        }

        // Update maximumPerson as the maximum of 
        // itself and currentPerson.
        maximumPerson = max(maximumPerson, currentPerson);
        
        // If current entry time is greater than the 
        // current exit time, decrease the currentPerson
        // by 1 and increase 'j'.
        while(i < n && entry[i] >= exit[j]){
            j++;
            currentPerson--;
        }
    }

    // Calculate the number of handshakes when maximumPerson guests
    // are present.
    int ans = (((long long)maximumPerson * (long long)(maximumPerson - 1)) / 2)%MOD;

    // Finally, return the ans.
    return ans;
}

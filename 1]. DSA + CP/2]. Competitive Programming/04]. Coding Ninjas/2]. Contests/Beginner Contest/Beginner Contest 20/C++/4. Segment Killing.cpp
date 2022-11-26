/*
    Time Complexity: O((M + N) * logN)
    Space Complexity: O(M + N)

    where 'M' is the number of monsters, 
    and 'N' is the number of types of attacks.
*/

#include <vector>
#include <queue>
using namespace std;

long long minimumAttacks(vector<int> &h, vector<int> &l, vector<int> &r, vector<int> &c) {
    
    // Declaring 'm' as the number of monsters, and 'n' as the number of types of attacks.
    int m = h.size(), n = l.size();

    /* Declaring array 'attacks' for storing all such that 'attacks[i]' is an array which 
    stores 'r[j]' and 'c[j]' for all the types of attacks that have 'l[j] = i'. */
    vector<vector<int>> attacks[m];

    // Iterating over all types of attacks to insert them into 'attacks'.
    for (int i = 0; i < n; ++i) {
        attacks[l[i]].push_back({r[i], c[i]});
    }

    // Declaring a maximum heap 'curAttacks' for storing the currently usable attacks.
    priority_queue<vector<int>> curAttacks;

    // Declaring a difference array 'd' for the updates of the damage done.
    vector<int> d(m + 1, 0);

    /* Declaring two variables, 'ans' for storing the final answer,
    and 'attacked' as the prefix sum for the difference array 'd'. */
    long long ans = 0, attacked = 0;

    // Iterating over all the monsters using a loop 'i' from 0 to 'm - 1'.
    for (int i = 0; i < m; ++i) {

        // Inserting all attacks stored in 'attacks[i]', to 'curAttacks'.
        for (auto j : attacks[i]) {
            curAttacks.push(j);
        }

        // Updating the prefix sum 'attacked'.
        attacked += d[i];

        // Updating the health of monster 'i' to its current health.
        h[i] -= attacked;

        // Running a loop till the monster 'i' is killed.
        while (h[i] > 0) {

            // Breaking from the loop if there are no currently usable attacks.
            if (curAttacks.empty()) {
                break;
            }

            // Declaring a variable 'temp' to store the attack on top of 'curAttacks' and pop it.
            vector<int> temp = curAttacks.top();
            curAttacks.pop();

            // Breaking from the loop if there are no attacks that can damage the current monster.
            if (temp[0] < i) {
                break;
            }

            // Declaring a variable 'damage' to store the number of times the attack must be used.
            int damage = min(h[i], temp[1]);

            // Updating 'ans'.
            ans += damage;
            
            // Updating the prefix sum 'attacked'.
            attacked += damage;
            
            // Updating the difference array 'd'.
            d[temp[0] + 1] -= damage;

            // Updating the health of the current monster 'i'.
            h[i] -= damage;
            
            /* Updating the uses left of the current selected attack, 
            and pushing it to 'curAttacks' if there are uses left. */
            temp[1] -= damage;
            if (temp[1] > 0) {
                curAttacks.push(temp);
            }
        }
        
        // Returning '-1' if the monster cannot be killed.
        if (h[i] > 0) {
            return -1;
        }
    }

    // Returning the final answer 'ans'.
    return ans;
}
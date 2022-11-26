/*
    Time Complexity: O(N * logN)
    Space Complexity: O(N)

    where 'N' is the total number of dishes.
*/

#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

long long maximumEnjoyment(int k, vector<int> &c, vector<int> &t) {
    
    // Declaring 'n' as the total number of dishes.
    int n = c.size();

    // Declaring 'dishes' which will store the tastiness and cuisine of each dish.
    vector<vector<int>> dishes;
    for (int i = 0; i < n; ++i) {
        dishes.push_back({t[i], c[i]});
    }

    // Sorting the dishes in descending order of their tastiness.
    sort(dishes.begin(), dishes.end(), greater<vector<int>>());

    // Declaring 'tot' for storing the total tastiness and 'var' for storing the variety.
    long long tot = 0, var = 0;

    // Declaring 'used' which stores if a dish from a certain cuisine has been selected.
    bool used[n + 1] = {0};

    // Declaring a maximum heap 'unselected' for storing the dishes that have not been selected.
    priority_queue<vector<int>> unselected;

    /* Declaring a minimum heap 'selected' for storing the currently selected dishes
    except those with the highest tastiness in their cuisine category. */
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> selected; 

    // Running a loop for iterating on the first 'k' dishes.
    for (int i = 0; i < k; ++i) {

        /* Pushing the current dish in 'selected' if another dish of the same cuisine is
        already selected; otherwise incrementing variety and marking its cuisine as present in 'used'. */
        if (used[dishes[i][1]]) {
            selected.push(dishes[i]);
        }
        else {
            used[dishes[i][1]] = 1;
            var++;
        }

        // Adding the current dish's tastiness to the total tastiness.
        tot += (long long)dishes[i][0];
    }

    // Running a loop on the remaining dishes and pushing them in 'unselected'.
    for (int i = k; i < n; ++i) {
        unselected.push(dishes[i]);
    }

    // Declaring 'ans' for storing the final answer with the value of the current answer.
    long long ans = tot + var * var;

    // Running a loop till there are no dishes to replace with or be replaced.
    while (!selected.empty() and !unselected.empty()) {

        // Declaring 'add' as the dish on top of 'unselected'.
        vector<int> add = unselected.top();
        unselected.pop();

        /* Continuing to next iteration if another dish with the cuisine category 
        of 'add' is already selected. */
        if (used[add[1]]) {
            continue;
        }
        
        /* Adding tastiness of 'add' to the total tastiness, marking its cuisine as
        present in 'used', and incrementing variety. */
        tot += (long long)add[0];
        used[add[1]] = 1;
        var++;

        // Declaring 'remove' as the dish on top of 'selected'.
        vector<int> remove = selected.top();
        selected.pop();

        // Subtracting tastiness of 'remove' from the total tastiness.
        tot -= (long long)remove[0];  

        // Updating 'ans' with the current answer.
        ans = max(ans, tot + var * var);
    }

    // Returning the final answer stored in 'ans'.
    return ans;
}
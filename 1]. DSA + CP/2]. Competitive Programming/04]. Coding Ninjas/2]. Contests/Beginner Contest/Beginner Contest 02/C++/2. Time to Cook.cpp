/*
    Time Complexity: O(N + M)
    Space Complexity: O(N)

    where 'N' is the number of food items on the menu and 'M' is the number of orders.
*/
int timeToCook(vector<int> time, vector<vector<int>> order)
{
    
    int n = time.size();
    int m = order.size();

    vector<long long> cook(n + 1 , 0);

    // Calculating the total time spent on each food item.
    for (int i = 0; i < m; ++i)
    {   
        int id = order[i][0];
        int amount = order[i][1];
        int tot = time[id - 1] * amount;

        cook[id] += tot;
    }

    int ans = -1;
    long long mxValue = 0;

    // Finding the first food item on which we spent maximum time.
    for (int i = 1; i < n + 1; ++i)
    {
        if (cook[i] > mxValue)
        {
            mxValue = cook[i];
            ans = i;
        }
    }

    return ans;
}
/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where ‘N’ is the length of the array.
*/


int minDays(vector<int> &a, int n, int m){

    int sum = 0;

    // Finding the number of complete cycles.
    for(int i = 0; i < n; i++){
        sum += a[i];
    }

    int ans = sum*(m/sum);
    int count = n*(m/sum);

    // Finding the rest number of days.
    for(int i = 0; i < n; i++){
        ans += a[i];
        if (ans > m){
            break;
        }
        count += 1;
    }
    return count;
}

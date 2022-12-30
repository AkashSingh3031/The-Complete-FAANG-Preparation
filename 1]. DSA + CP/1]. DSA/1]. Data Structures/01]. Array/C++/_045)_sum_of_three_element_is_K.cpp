/* An array of n elements, find three elements in the array, such that, their sum is equal to the
given element K of that array.*/

#include <bits/stdc++.h>
using namespace std;

bool Triplet(int arr[], int arr_size, int sum)
{
    int l, r, m; // for left ,right and middle
    sort(arr, arr + arr_size);
    for (int i = 0; i < arr_size - 2; i++)
    {
        l = 0;
        r = arr_size - 1;
        m = (l + r) / 2;
        while (l < r)
        {
            if (arr[l] + arr[m] + arr[r] == sum)
            {
                cout << "Triplet is: " << arr[l] << "," << arr[m] << "," << arr[r];
                return true;
            }
            else if (arr[l] + arr[m] + arr[r] < sum)
                l++;
            else
                r--;
        }
    }
    return false;
}
int main()
{
    int n, k, arrsize;
    cout << "Enter number of elements:";
    cin >> n;
    int array[n];
    cout << "Enter the elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << "Enter the sum:";
    cin >> k;

    for (int i = 0; i < n; i++)

        arrsize = sizeof(array) / sizeof(array[0]);
    Triplet(array, arrsize, k);

    return 0;
}

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the number of chocolate bags / elements in array 'A'.
*/

int chooseBag(int n, vector<int>& a)
{
    // Create variables to hold sum, count of even elements and count of odd elements.
    long long sum = 0;
    int evenCount = 0, oddCount = 0;

    // Traverse through the array.
    for(int i = 0; i < n; i++)
    {
        sum += a[i];

        // Count odd and even elements.
        if(a[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }

    // Return answer based on the parity of the sum of array.
    if(sum % 2 == 0)
    {
        return evenCount;
    }
    else
    {
        return oddCount;
    }
}

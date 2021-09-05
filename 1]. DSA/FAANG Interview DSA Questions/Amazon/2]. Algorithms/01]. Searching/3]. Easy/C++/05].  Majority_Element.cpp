#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int candidate(int a[], int size)
	{
		int count = 1, maj_index = 0;
		for (int i = 0; i < size; i++)
		{
			if (a[maj_index] == a[i])
				count++;
			else
				count--;
			if (count == 0)
			{
				maj_index = i;
				count = 1;
			}
		}
		return a[maj_index];
	}
	
    int majorityElement(int a[], int size)
    {
        // your code here
        int count = 0, ele;
		ele = candidate(a, size);
		for (int i = 0; i < size; i++)
			if (a[i] == ele)
				count++;
		if (count > size / 2)
			return ele;
		else
			return -1;
    }
};

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }
    return 0;
}

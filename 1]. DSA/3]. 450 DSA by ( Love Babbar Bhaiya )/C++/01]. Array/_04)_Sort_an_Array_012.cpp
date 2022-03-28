/*
Example 1:
    Input: 
        N = 5
        arr[]= {0 2 1 2 0}
    Output:
        0 0 1 2 2
    
  Explanation:
    0s 1s and 2s are segregated 
    into ascending order.

Example 2:
    Input: 
        N = 3
        arr[] = {0 1 0}
    Output:
        0 0 1
  
  Explanation:
    0s 1s and 2s are segregated 
    into ascending order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here
        int low = 0, high = n-1, mid = 0;
        
        while(mid <= high)
        {
            switch(a[mid])
            {
                case 0:
                    swap(a[low++], a[mid++]);
                    break;
                    
                case 1:
                    mid++;
                    break;
                    
                case 2:
                    swap(a[mid], a[high--]);
                    break;
            }
        }
    }
    
};

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

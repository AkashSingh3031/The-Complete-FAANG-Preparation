/*
Example 1:
    Input: N = 5, arr = {1, 2, 3, 2, 1}
    Output: 3
  Explaination: Only the number 3 is single.
Example 2:
    Input: N = 11, arr = {1, 2, 3, 5, 3, 2, 1, 4, 5, 6, 6}
    Output: 4
  Explaination: 4 is the only single.
*/

class Solution{
    static int findSingle(int N, int arr[]){
        // code here
        int m = 0;
        for(int i=0; i<N; i++)
            m ^= arr[i];
        return m;
    }
}

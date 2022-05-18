#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        //Your code here
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < N; i++) {
          
            pq.push(arr[i]);
        }
    
        int prev = pq.top();
        pq.pop();
        int c = 1;
        int max = 1;
        while (!pq.empty()) {
          
            if (pq.top() - prev > 1) {
                c = 1;
                prev = pq.top();
                pq.pop();
            }
    
            else if (pq.top() - prev == 0) {
                prev = pq.top();
                pq.pop();
            }
          
            else {
              
                c++;
                prev = pq.top();
                pq.pop();
            }
          
            if (max < c) {
                max = c;
            }
        }
        return max;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
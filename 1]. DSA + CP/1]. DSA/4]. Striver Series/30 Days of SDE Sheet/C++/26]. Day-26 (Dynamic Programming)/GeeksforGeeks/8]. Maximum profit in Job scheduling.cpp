// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    bool static comparator(Job &a,Job &b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       // your code here
        vector<int>v;
        if(n==0){
            return v;
        }
        
        sort(arr,arr+n,comparator);
        int max_deadline = 0;
        for(int i=0;i<n;i++){
            max_deadline = max(max_deadline, arr[i].dead);
        }
        
        int jobprofit=0;
        int jobcount=0;
        vector<int>filled(max_deadline+1, -1);
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(filled[j]==-1){
                    filled[j]=i;
                    jobprofit+=arr[i].profit;
                    jobcount++;
                    break;
                }
            }
        }
        v.push_back(jobcount);
        v.push_back(jobprofit);
        return v;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends
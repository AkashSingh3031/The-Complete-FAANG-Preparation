

/* 

    Solution by Rahul Surana

    ***********************************************************

Monk recently taught Fredo about sorting. Now, he wants to check whether he understood the concept or not. 
So, he gave him the following algorithm and asked to implement it:

Assumptions:
We consider the rightmost digit of each number to be at index 1, 
second last at index 2 and so on till the leftmost digit of the number.
Meaning of ith chunk: This chunk consists of digits from position 5 * i to 1 + 5 * (i - 1) in the given number.
If there is no digit at some position in the number, take the digit to be 0.

Initially, i is 1.

Construct the ith chunk, for all of the integers in the array. 
Let's call the value of this chunk to be the weight of respective integer in the array.
If weight of all the integers of the array is 0, then STOP
Sort the array according to the weights of integers. 
If two integers have same weight, then the one which appeared earlier should be positioned earlier after the sorting is done. 
The array changes to this sorted array.
Increment i by 1 and repeat from STEP 1
See the sample explanation for a better understanding.
So, Fredo understood the concept and coded it. 
Now, Monk asks you to write the code for the algorithm to verify Fredo's answer.

Input:
The first line of the input contains N denoting the number of elements in the array to be sorted.
The next line contains N single space separated integers denoting the array elements.

    ***********************************************************

*/

#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define FOR(i,a)     for(int i = 0; i < a; ++i)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
int inf=1e9+7,MOD=1e9+7;

ll int first5[1000000],full[1000000];
ll int tempfirst5[1000000],tempfull[1000000];
ll int iter;

void merge(int start, int mid, int end){
    int m = start;
    int n = mid;
    int pointer = start;
    while ((m < mid && n <= end)){
        if(first5[m] > first5[n]) {
            tempfull[pointer] = full[n];
            tempfirst5[pointer++] = first5[n++];
        } else {
            tempfull[pointer] = full[m];
            tempfirst5[pointer++] = first5[m++];
        }
    }
    while (m<mid) {
        tempfull[pointer] = full[m];
        tempfirst5[pointer++] = first5[m++];
    }
    while (n<=end) {
        tempfull[pointer] = full[n];
        tempfirst5[pointer++] = first5[n++];
    }
    for(int i = start; i <= end; i++){
        first5[i] = tempfirst5[i];
        full[i] = tempfull[i];
        // cout << full[i] << " ";
    }
}

void mergesort(int l,int r){
    if(l<r) {
        int mid = (l + r) >> 1;
        mergesort(l, mid);
        mergesort(mid + 1, r);
        merge(l, mid + 1, r);
    }
}

int main()
{
	fast_io;
    int n;
    cin >> n;

    ll int k = 0;
    FOR(i,n) { cin >> full[i]; if(k<full[i]) k = full[i]; }
    // cout<<k<<"\n";
    // FOR(i,n) cout << full[i] << " ";
    iter = 1;
    while(k / iter) {
        FOR(i,n) first5[i] = (full[i] / iter) % 100000;
        
        mergesort(0,n-1);
        FOR(i,n) cout << full[i] << " ";
        cout << "\n";
        iter*=100000; 
    }
}
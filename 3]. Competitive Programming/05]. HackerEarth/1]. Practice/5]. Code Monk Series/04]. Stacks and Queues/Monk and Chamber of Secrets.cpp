
/* 

     Solution by Rahul Surana

    ***********************************************************

Hagrid says "follow the spiders" and so Harry and Ron head to the Forbidden Forest. 
There they meet Aragog, a giant spider who tells them about the innocence of Hagrid. 
But Aragog only allows Hagrid to go back. These boys have got into a serious trouble now.

The only way to escape as Aragog says is to answer a question.
Aragog shows them a queue of N spiders of which only X spiders are to be selected. 
Each spider has some power associated with it. There are X iterations on the queue.
In each iteration, X spiders are dequeued (if queue has less than X entries, 
all of them will be dequeued) and the one with maximum power is selected and remaining spiders are enqueued back to the queue 
(in the order they were dequeued) but their power is decreased by one unit. 
If there are multiple spiders with maximum power in those dequeued spiders, the one which comes first in the queue is selected. 
If at any moment , power of any spider becomes 0, it can't be decremented any further, it remains the same.
Now, Aragog asks the boys to tell him the positions of all the selected spiders (positions in the initial given queue) in the order they are selected. 
As the boys are frightened and can't think of anything , they call Monk for the rescue. Help Monk to get the answer fast and save the boys.

Input Format:
The first line consists of two space separated integers N and X, denoting the number of spiders in the queue and the number of spiders that have to be selected respectively.
The next line consists of an array A, A[i] denoting the power of spider at position i (1 <= i <= N).

Output Format:
For each of the X iterations, output the position of the selected spider in that iteration. 
Position refers to the index at which the spider was present in the initial given queue (1 based indexing).


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
#define FOR(i,a)     for(int i = 0; i < a; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000007 
using namespace std;


int main()
{
	fast_io;
    int n, x;
    cin >> n >> x;
    int ar[n];
    queue<int> q;
    FOR(i,n) { cin >> ar[i]; q.push(i); }
    int index = 0;
    FOR(i,x) {
        queue<int> a;
        int m = -1;
        FOR(j,x) {
            if(!q.empty()){
                if(m <= ar[q.front()]) m = ar[q.front()]; 
                // cout << q.front() << " ";
                a.push(q.front());
                q.pop();
            }
        }
        bool f = false;
        int ans = -1;
        FOR(j,x) {
            if(!a.empty()){
                if(m == ar[a.front()] && !f) {
                    f = true; 
                    ans = a.front()+1; 
                    a.pop(); 
                } 
                if(!a.empty()){
                    if(ar[a.front()]>0)
                    ar[a.front()] -= 1;
                    q.push(a.front());
                    a.pop();
                }
            }
        }
        cout << ans << " ";
    }
}


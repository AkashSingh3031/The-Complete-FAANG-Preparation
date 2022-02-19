  

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Voldemort has a big army, so he has maintained his people in N rows to fight Harry's army. 
Each row contains the heights of the fighters and is sorted in non-decreasing order from the start to end, 
except for the first row, which may contain the heights of the fighters in any arbitary order, as it contains all the legendry fighters.

During the war, at any time, Voldemort can remove a fighter from any row, 
and can also add any new fighter to any row (maintaining the non-decreasing order of heights. except in the first row).


Note:

1. Voldemort will never remove any fighter from an empty row.

2. Voldemort can only remove or add a fighter from/to the end of row.


Now Harry has a special wand which can kill exactly N fighters in one go, but with following conditions:

1. There should be exactly N fighters, and exactly one fighter (which can be anyone in the row) should be chosen from each row.

2. The first fighter can only be chosen from the first row, the second one from second row, and so on. 
Basically the ith fighter should be chosen from ith the row, where i ranges from 1 to N.

3. The order of the heights of the chosen fighters should be strictly increasing.


Now Harry wants to know whether he can kill N fighters using special wand. As Harry is busy in fighting Voldemort, he gave this task to Monk.


Input Format:

The First line consists of a single integer N denoting the number of stacks.
In each of the next N lines, first integer X denotes the size of the stack, 
followed by the X space separated integers denoting the heights of the fighters in the stack.

The next lines consists of single integer Q, denoting the number operations.
Each of the next Q lines will contain a integer v, which will decide the type of operation.

1. For v = 1, extra 2 integers k and h will be given , which shows that Voldemort will add one fighter of height h in kth stack, 
maintaining the order of the stack, if k is not equal to 1 .

2. For v = 0, 1 more integer k will be given, which shows that Voldemort will remove a fighter from kth stack.

3. For v = 2, Monk needs to know whether Harry can use his special wand or not.


Output Format: :

For each v = 2, print "YES" (without quotes) if Harry can use his special wand or print "NO" (without quotes).


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

vector<int> st[10];
stack<int> aa;

int binarySearch(int i,int low,int high, int key) {
    int mid;
    while(low < high) {
        mid = (low + high) >> 1;
        if(st[i][mid] > key)
            high = mid;
        else low = mid + 1;
    }
    // cout << st[i][low]<< "k " << key <<"l " << low <<"h "<< high<<" ";
    if(st[i][low] > key) return low;
    return -1;

}

int main()
{
	fast_io;
    int n;
    cin >> n;
    FOR(i,n) {
        int s;
        cin >> s;
        FOR(j,s) { int a; cin >> a; st[i].pb(a); } 
    }
    aa.push(st[0][0]);
    FOR(i,st[0].size()-1) {
        if(st[0][i+1] > aa.top()) aa.push(aa.top());
        else aa.push(st[0][i+1]);
    }
    int q;
    cin >> q;
    FOR(i,q) {
        int v,a,b;
        cin >> v;
        if(v == 0) {
            cin >> a;
            st[a-1].pop_back();
            // cout << st[a-1][st[a-1].size()-1] << "\n";
            if(a == 1) aa.pop();
        }
        if(v == 1) {
            cin >> a >> b;
            st[a-1].pb(b);
            // cout << st[a-1][st[a-1].size()-1] << "\n";
            if(a == 1) {
                if(aa.top() > b) aa.push(b);
                else aa.push(aa.top());
            }
        }
        if(v == 2) {
            
            int premi = aa.top();
            bool f;
            FOR(j,n-1){
                int index = binarySearch(j+1,0,st[j+1].size()-1,premi);
                if(index == -1) { f = true; break; }
                int min = st[j+1][index];
                // cout << premi<<"\n";
                premi = min; 
                f= false;
            }
            // cout << premi<<"\n";
            if (f) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }
    }
}

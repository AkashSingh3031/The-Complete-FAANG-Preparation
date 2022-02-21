/* 

    Solution by Rahul Surana

    ***********************************************************

Albus Dumbledore announced that the school will host the legendary event known as Wizard Tournament where four magical schools are going to 
compete against each other in a very deadly competition by facing some dangerous challenges. 
Since the team selection is very critical in this deadly competition. Albus Dumbledore asked Little Monk to help him in the team selection process. 
There is a long queue of students from all the four magical schools. Each student of a school have a different roll number. 
Whenever a new student will come, he will search for his schoolmate from the end of the queue. 
As soon as he will find any of the schoolmate in the queue, he will stand behind him, otherwise he will stand at the end of the queue. 
At any moment Little Monk will ask the student, who is standing in front of the queue, to come and put his name in the Goblet of Fire and remove him from the queue. 
There are Q operations of one of the following types:

-> E x y : A new student of school x (1 <= x <= 4) whose roll number is y (1 <= y <= 50000) will stand in queue according to the method mentioned above.

-> D: Little Monk will ask the student, who is standing in front of the queue, to come and put his name in the Goblet of Fire and remove him from the queue

Now Albus Dumbledore asked Little Monk to tell him the order in which student put their name. 
Little Monk is too lazy to that so he asked you to write a program to print required order.

Note: Number of dequeue operations will never be greater than enqueue operations at any point of time.

Input Format:
First line contains an integer Q (1 <= Q <= 100000), denoting the number of operations. Next Q lines will contains one of the 2 types of operations.

Output Format:
For each 2nd type of operation, print two space separated integers, the front student's school and roll number.

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

vector<queue<pi>> st;

int main()
{
	fast_io;
    int q;
    cin >> q;
    int count[4];
    FOR(i,4) count[i] = 0;
    int starter = 0;
    while(q--) {
        char a;
        cin >> a;
        if(a == 'E') {
            int x, y;
            cin >> x >> y;
            int j = 0;
            while(j < st.size() && st[j].front().F != x) j++;
            int c = starter;
            if(j==st.size()){
                queue<pi> m;
                m.push({x,y});
                st.pb(m); 
                count[x-1]++;
            }
            else{
                count[x-1]++;
                st[j].push({x,y});
            }
        }
        else if(a == 'D') {
            count[st[0].front().F - 1]--;
            cout << st[0].front().F << " " << st[0].front().S << "\n";
            st[0].pop();
            if(st[0].empty()) st.erase(st.begin()); 
        }
    }
}

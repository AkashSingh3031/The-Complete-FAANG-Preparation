

/* 
    Solution by Rahul Surana
    
    ***********************************************************

In addition to CP, Chef recently developed an interest in Web Development and started learning HTML. Now he wants to create his own HTML Code Editor. 
As a subproblem, he wants to check if a typed HTML closing tag has correct syntax or not.

A closing HTML tag must:

-> Start with "</"
-> End with ">"
-> Have only lower-case alpha-numeric characters as its body (between "</" and ">"). That is, each character of the body should either be a digit or a lower-case English letter.
-> Have a non-empty body.

Help Chef by printing "Success" if the tag is fine. If not, print "Error".

Input

The first line contains an integer T, the number of test cases. Then T test cases follow.
Each test case is a single line of input, a string describing the tag we need to check.

Output

For each test case, output in a single line, "Success" if it is a valid closing tag and "Error" otherwise (without quotes).

You may print each character of the string in uppercase or lowercase (for example, the strings "SuccEss", "success", "Success", "SUCCESS" et cetera will all be treated as identical).


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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

int main()
{
    fast_io;
    int t;
    cin >> t;
    FOR(i,t) {
        string a;
        cin >> a;
        if(a.length() > 3){
            if(a.substr(0,2) != "</") cout << "Error\n";
            else {
                if(a.substr(a.size()-1,1) != ">") cout << "Error\n";
                else{
                    bool f = true;
                    for(int i = 2; i < a.size()-1; i++){
                        if((!isalpha(a[i]) && !isdigit(a[i]))) {
                            f= false;
                        }
                        if(isalpha(a[i]) && !islower(a[i])) f = false;
                    }
                    if(f) cout << "Success\n";
                    else cout << "Error\n";
                }
            } 
            
        }
        else {
            cout << "Error\n";
        }

    }
}

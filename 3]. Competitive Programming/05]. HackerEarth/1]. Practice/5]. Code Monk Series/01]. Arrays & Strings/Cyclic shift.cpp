

/* 

    Solution by Rahul Surana

    ***********************************************************

A large binary number is represented by a string  of size A and N comprises of 0s and 1s. 
You must perform a cyclic shift on this string. The cyclic shift operation is defined as follows:

If the string A is [a0,a1,a2,...,a(n-1)], then after performing one cyclic shift, the string becomes [a1,a2,a3,...,a0].

You performed the shift infinite number of times and each time you recorded the value of the binary number represented by the string. 
The maximum binary number formed after performing (possibly 0) the operation is B. 
Your task is to determine the number of cyclic shifts 
that can be performed such that the value represented by the string A will be equal to B for the kth time.

Input format

First line: A single integer T denoting the number of test cases
For each test case:
First line: Two space-separated integers N and K 
Second line: A denoting the string

    ***********************************************************

*/

#include <bits/stdc++.h>
#define ll          unsigned long long int
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

vector<int> z_function(string s)
{
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
vector<int> sort_cyclic_shifts(string const& s)
{
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for(int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
string flip(string s)
{
    string a;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i] == '0')
            a += '1';
        else
            a += '0';
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        ll n,p;
        cin>>n>>p;
        cin>>s;
        s = flip(s);
        vector<int> z = z_function(s);
        // for(ll i = 0; i < z.size(); i++){ cout << z[i]<<" ";}
        ll period=n;
        for(ll i=1;i<n;i++)
        {
            if(i+z[i] == n && n%i == 0)
            {
                period = i;
                break;
            }
        }
        string A = s.substr(0,period);
        vector<int> v = sort_cyclic_shifts(A);
        ll ans = v[0] + (p-1)*period;
        cout<<ans<<"\n";
    }
    return 0;
}

// <------------------------------------END-------------------------------------------> \\


// #include <bits/stdc++.h>
// #define ll          unsigned long long int
// #define vl          vector<ll>
// #define vi          vector<int>
// #define pi          pair<int,int>
// #define pl          pair<ll,ll>
// #define all(a)      a.begin(),a.end()
// #define mem(a,x)    memset(a,x,sizeof(a))
// #define pb          push_back
// #define mp          make_pair
// #define F           first
// #define S           second
// #define FOR(i,a)     for(int i = 0; i < a; i++)
// #define trace(x)    cerr<<#x<<" : "<<x<<endl;
// #define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
// #define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
// #define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

// using namespace std;



// ll binaryToDecimal(string n)
// {
//     string num = n;
//     ll dec_value = 0;
 
//     // Initializing base value to 1, i.e 2^0
//     ll base = 1;
 
//     ll len = num.length();
//     for (int i = len - 1; i >= 0; i--) {
//         if (num[i] == '1')
//             dec_value += base;
//         base = base * 2;
//     }
 
//     return dec_value;
// }


// void solve() {
//     vector<int> index;
//     ll n,k;
//     cin >> n >> k;
//     string s,copy;
//     cin >> s;

//     // copy2 = s;
//     copy = s;
//     // cout << s << "\n";
//     for(ll i=0;i<n;i++){
//         // cout << "stoi(s) "<<stoi(s)<<" ";
//         // ll a = binaryToDecimal(s);
//         if(s >= copy){
            
//             if ((bool)(s==copy)){
//                 index.push_back(i);
//             }
//             else { index.clear(); copy = s; index.push_back(i);}
//             // m = a;
//             // cout << "copy "<<copy<<" ";
//             // cout << "a :" << a<<" ";
//         }
//         reverse(s.begin()+1, s.end());
//         reverse(s.begin(), s.end());
//     }
//     cout << "copy "<< s<< "\n";
//     // cout <<"after the max"<< s << "\n";
//     // for (ll i = 0; i < n; i++){
//     //     if ((bool)(s==copy)){
//     //         index.push_back(i);
//     //     }
//     //     reverse(s.begin()+1, s.end());
//     //     reverse(s.begin(), s.end());
        
//     // }
//     // cout << s << "\n";
//      for (ll i = 0; i < index.size(); i++){ cout << index[i]<<" ";}
//     ll x = (int)k/index.size();
//     int y = k%index.size();
//     cout <<"\n"<< index.size() <<" "<< x-1 <<" "<< n <<" "<< (x-1)*n<< " " << y <<"\n";
//     if(x==0) cout << index[y-1] <<"\n";
//     else if(y==0 && x!=0) cout <<((x-1)*n + index[index.size()-1]) << "\n";
//     else cout << (x)*n + index[y-1] << "\n";
// }

// int tc;

// int main() {
//     fast_io;

//     cin >> tc;
//     for (int t = 1; t <= tc; t++) {
//         solve();
//     }
// }
    



/*#include <bits/stdc++.h>
#define ll          unsigned long long int
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
 
string maxone(string s){
    string temp=s+s;
    int p =0,mo=0,count=0;
    string ans = "";
    for(ll i=0; i < 2*s.length();i++){
        if(s[i%s.length()]=='1') count++;
        else count = 0;

        if(count>=mo && s.substr((s.length()+p-mo+1)%s.length())+ s.substr(0,(s.length()+p-mo+1)%s.length())>ans) {mo=count; p = i%s.length(); ans = s.substr((s.length()+p-mo+1)%s.length())+ s.substr(0,(s.length()+p-mo+1)%s.length());}

    }
    return ans;
}


void solve() {
    vector<int> index;
    ll n,k;
    cin >> n >> k;
    string s,copy;
    cin >> s;

    // copy2 = s;
    copy = maxone(s);
    // cout << s << "\n";
    // for(ll i=0;i<n;i++){
    //     if(s >= copy){
    //         if ((bool)(s>copy)){
    //             index.clear();
    //             index.pb(i);
    //             copy = s;
    //         }
    //         else { index.pb(i);}
    //         // m = a;
    //         // cout << "copy "<<copy<<" ";
    //         // cout << "a :" << a<<" ";
    //     }
    //     reverse(s.begin()+1, s.end());
    //     reverse(s.begin(), s.end());
    // }
    // cout << "copy "<< s<< "\n";
    // cout <<"after the max"<< s << "\n";
    // index.push_back(0);
    for (ll i = 0; i < n; i++){
        if ((bool)(s==copy)){
            index.push_back(i);
        }
        reverse(s.begin()+1, s.end());
        reverse(s.begin(), s.end());
        
    }
    // cout << s << "\n";
    //  for (ll i = 0; i < index.size(); i++){ cout << index[i]<<" ";}
    int x = k / index.size();
    int y = k % index.size();
    // cout <<"\n"<< index.size() <<" "<< x <<" "<< n <<" "<< (x)*n<< " " << y <<"\n";
    if(x==0) cout << index[y-1] <<"\n";
    else if(y==0 && x!=0) cout <<((x-1)*n + index[index.size()-1]) << "\n";
    else cout << (x)*n + index[y-1] << "\n";
}

int tc;

int main() {
    fast_io;

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
        // cout << maxone("1111101110111111100111111111101111111011111010101011111111111011011110101111111111010111111110111111111111101111111011110111111111111101011110111111011111111011100111111111111111111110110111111001111101111101110100101100111111111111011110111111111110011110100110111111111101111100111011111111101111111111111110111111101111010010110111110100001101111011100011111101011111011011111111111000101011011111001111111111111111111111000111111111111011111111111111110110011111101111010111111111111110111111111011111111010111111110111001111111111111111000010111101111110110111111111111110111011111111111111110110111111111111111110111011101111010111111111111011111111111101111011111111011111011011111111111101111100011111111111011111011110111110111111111111111111101110111111110100111111101111110111010111111111111111111111101111011100111111101111111011111101101111110111001111100111111111111011110111011011111111111111111011111111101101101111011110101101100111110111110111011011111110110110101111111111110100111");
    }
}*/

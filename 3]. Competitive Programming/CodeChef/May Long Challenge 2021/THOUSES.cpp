/*
There is a large tree house in an unknown world. It is ruled by the great emperor KZS. It consists of N nodes numbered from 1 to N in which the people of that world reside. 
The nodes are organized in a tree structure rooted at node 1. You need to assign values to the nodes according to the wishes of emperor KZS which are as follows :-
The value of node 1 is X.
All immediate children of any node have pairwise distinct values.
For every node with at least one immediate child, the gcd of the values of all immediate children is equal to the value of the node.
The total sum of the values of all nodes should be minimum.
The greatest common divisor gcd(a,b) of two positive integers a and b is equal to the largest integer d such that both integers a and b are divisible by d.
Print the sum of all values, modulo 109+7.
Input
The first line contains an integer T, the number of test cases. T testcases follow.
The first line of each test contains two integers N and X.
Each of the following N−1 lines contains two integers u and v, denoting an edge between nodes u and v.
Output
For each test case, print the sum of values, modulo 109+7.
Sample Input
2
4 1
1 2
1 3
1 4
8 1
1 2
1 3
2 4
2 5
5 6
5 7
7 8
Sample Output
7
11
*/

#pragma GCC optimize("Ofast", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
using pii = pair<int, int>;
template<typename T>
using Prior = std::priority_queue<T>;
template<typename T>
using prior = std::priority_queue<T, vector<T>, greater<T>>;

#define X first
#define Y second
#define eb emplace_back
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define fastIO() ios_base::sync_with_stdio(0), cin.tie(0)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int getRand(int L, int R) {
    if (L > R) swap(L, R);
    return (int)(rng() % (uint64_t)(R - L + 1) + L);
}

template<typename T1, typename T2>
ostream& operator << (ostream &os, pair<T1, T2> p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template<typename T>
ostream& operator << (ostream &os, vector<T> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}

const int maxn = 3E5 + 5;
const int mod = 1E9 + 7;

vector<int> adj[maxn], subval, val;
vector<pii> ch;

void dfs(int now, int lst = -1) {
    for (auto x : adj[now]) {
        if (x == lst) continue;
        dfs(x, now);
    }

    ch.clear();
    for (auto x : adj[now]) {
        if (x != lst) ch.eb(subval[x], x);
    }
    sort(RALL(ch));

    int tok = 1;
    for (auto [_val, id] : ch) val[id] = tok++;
    for (auto x : adj[now]) {
        if (x != lst) subval[now] += val[x] * subval[x];
    }
}

void solve() {
    int N, X; cin >> N >> X;

    subval.assign(N, 1), val.assign(N, 0);
    for (int i = 0; i < N; ++i) vector<int>().swap(adj[i]);

    for (int i = 0; i < N-1; ++i) {
        int u, v; cin >> u >> v, --u, --v;
        adj[u].eb(v), adj[v].eb(u);
    }

    dfs(0);

    cout << subval[0] % mod * X % mod << "\n";
}

int32_t main() {
    fastIO();

    int t = 1; cin >> t;
    for (int _ = 1; _ <= t; ++_) {
        // cout << "Case #" << _ << ": ";
        solve();
    }

    return 0;
}

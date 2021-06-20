#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
void solve()
{
int i;
int n, m;
cin >> n >> m;
int a[n];
int b[m];
for (i = 0; i < n; i++)
{
cin >> a[i];
}
for (i = 0; i < m; i++)
{
cin >> b[i];
}
int max = 1e9;
map<int, int> mp;
for (i = 0; i < n; i++)
{
if (i == 0)
mp[i] = 0;
else if (a[i] != 0)
mp[i] = 0;
else
mp[i] = max;
}
int right = -1;
for (i = 0; i < n; i++)
{
if (a[i] == 1)
right = i;
if (right != -1)
{
if (a[i] == 0)
mp[i] = min(mp[i], i - right);
}
}
int left = -1;
for (i = n - 1; i >= 0; i--)
{
if (a[i] == 2)
left = i;
if (left != -1)
{
if (a[i] == 0)
mp[i] = min(mp[i], left - i);
}
}
for (i = 0; i < m; i++)
{
int j = b[i] - 1;
if (mp[j] != max)
cout << mp[j] << " ";
else
cout << -1 << " ";
}
cout << "\n";
}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
// t = 1;
int _ = 1;
while (t--)
{
// cout<<"Case #"<<_++<<": ";
solve();
}
return 0;
}

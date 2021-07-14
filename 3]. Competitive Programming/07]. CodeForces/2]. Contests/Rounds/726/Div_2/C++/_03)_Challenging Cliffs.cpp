#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "rfd_wrap.h"
#else
#define fap(...) 0
#endif

typedef long long ll;
typedef pair<int, int> pii;

#define bt(x) (1LL << (x))
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 2e18;

auto prep(auto a, int p) {
	auto ret = a;
	ret.clear();
	ret.push_back(a[p+1]);
	for(int i=p+2; i<(int) a.size(); ++i) ret.push_back(a[i]);
	for(int i=0; i<p; ++i) ret.push_back(a[i]);
	ret.push_back(a[p]);
	return ret;
}

int main() {
	FastIO;

	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for(int& x : a) cin >> x;
		sort(all(a));

		if(n > 2) {
			int idx = 0, best = inf;
			for(int i=0; i+1<n; ++i) {
				if(a[i+1] - a[i] < best) {
					best = a[i+1] - a[i];
					idx = i;
				}
			}
			a = prep(a, idx);
		}

		for(int x : a) cout << x << " ";
		cout << "\n";
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds

#define eps 1e-7
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 300031;

int n, ar[N];
int k, x;
vector<pair<int, int> > order;
set<int> S;
set<int>::iterator it;
long long ANS;
vector<pair<long long, long long> > T;
long long C[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> x >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		order.push_back(make_pair(ar[i], i));
	}

	S.insert(0);
	S.insert(n+1);

	sort(order.begin(), order.end());

	reverse(order.begin(), order.end());

	for (int i = 0; i < order.size(); i++)
	{
		int ps = order[i].second;
		it = S.lower_bound(ps);
		int val1 = (*it);
		--it;
		int val2 = (*it);
//		cout << val1 << " " << val2 << endl;

		long long here = (val1 - ps) * 1ll * (ps - val2 );
		//cout << here << "%" << ar[ps] << endl;
		ANS += 1ll * here*ar[ps];
		C[ps] = here;
		S.insert(ps);
	}
	//cout << ANS << endl;

	S.clear();
	sort(order.begin(), order.end());
	S.insert(0);
	S.insert(n + 1);

	for (int i = 0; i < order.size(); i++)
	{
		int ps = order[i].second;
		it = S.lower_bound(ps);
		int val1 = (*it);
		--it;
		int val2 = (*it);
		//		cout << val1 << " " << val2 << endl;

		long long here = (val1 - ps) * 1ll * (ps - val2);
		//cout << here << "%" << ar[ps] << endl;
		ANS -= 1ll * here*ar[ps];
		//T.push_back(make_pair(here, ps));
		C[ps] -= here;
		S.insert(ps);
		T.push_back(make_pair(C[ps], ps));
	}

	/*for (int i = 1; i <= n; i++)
	{
		cout << C[i] << " ";
	}
	cout << endl;
	*/
	sort(T.begin(), T.end());
	reverse(T.begin(), T.end());

	for (int i = 0; i < x; i++)
	{
		if (T[i].first>0)
			ANS += T[i].first;
	}
	cout << ANS << endl;

	cin.get(); cin.get();
	return 0;
}

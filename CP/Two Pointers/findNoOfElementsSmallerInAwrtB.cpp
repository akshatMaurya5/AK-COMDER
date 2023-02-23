#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << "=" << x <<'\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

// TC
// 4
// 4 5 6 7
// 1 2 3 6


void solve()
{
	ll n;
	cin >> n;
	vi a(n), b(n);
	// cin >> a >> b;
	for (auto &it : a)
	{
		cin >> it;
	}
	for (auto &it : b)
	{
		cin >> it;
	}

	vi ans(n);
	ll k = 0;

	ll i = 0, j = 0;

	while (i < n)
	{
		while (j < n && b[j] < a[i])
		{
			j++;
		}
		ans[i] = j;
		i++;
	}

	for (auto &it : ans)
	{
		cout << it << " ";
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
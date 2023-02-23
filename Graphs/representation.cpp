#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << "=" << x <<'\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;

	vector<int>adj[n+1];

	for(int i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>u;
		adj[u].pb(v);
		adj[v].pb(u);
	}



	return 0;
}
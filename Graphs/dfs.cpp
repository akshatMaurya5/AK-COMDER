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
//adj[n+1] generally
vi adj[100005];
int vis[10005];

void dfs(ll node)
{
	cout<<node<<' ';
	vis[node]=1;

	for(auto &it:adj[node])
	{
		if(vis[it]==0)
		{
			dfs(it);
			vis[it]=1;
		}
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
	ll n, m;
	cin >> n >> m;


	memset(vis,6,sizeof(vis));


	f(i,0,5)
	{
		cout<<vis[i]<<' ';
	}

	for(int i=1;i<=m;i++)
	{
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0){
			dfs(i);
		}
	}


	return 0;
}
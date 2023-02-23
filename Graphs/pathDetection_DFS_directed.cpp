#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << "=" << x <<'\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
int vis[100005],int pathVis[100005];

bool dfs(ll node)
{
	vis[node]=1;
	pathVis[node]=1;

	for(auto it:adj[node])
	{
		if(!vis[it])
		{
			if(dfs(it)==true)
			{
				return true;
			}
		}
		else if(vis[it]==1 && pathVis[node]==1)
		{
			return true;
		}
	}
	//else backtrack
	pathVis[node]=0;
	return false;
}

void checKCycle()
{
	bool ans=false;

	f(i,0,n+1)
	{
		if(!vis[i])
		{
			if(dfs(i))
			{
				ans=true;
				break;
			}
		}
	}
	ans?cout<<"YES\n":cout<<"NO\n";

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
       
    return 0;
}
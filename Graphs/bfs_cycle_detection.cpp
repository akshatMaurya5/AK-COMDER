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

bool bfsCycle(ll node)
{
	queue<pii>q;
	q.push({node,0});
	vis[node]=1;

	while(!q.empty())
	{
		int node=q.front().first;
		int parent=q.front().second;
		q.pop();

		for(auto &it:adj[node])
		{
			if(!vis[it])
			{
				q.push({it,node});
				vis[it]=1;
			}
			else if(vis[it]==1 && it!=parent)
			{
				return true;
			}
		}

	}
	return false;
}

void checKCycle()
{
	bool ans=false;

	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(bfsCycle(i)==true){
				ans=true;
				break;
			}
		}
	}
	ans?cout<<"Cycle detected\n":cout<<"No cycle\n";
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
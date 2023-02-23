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
#define MAX 1000

vvi adj(MAX);
vi euler(2 * MAX);
vi vis(MAX);

void addEdge(ll u, ll v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

void getEulerTour(ll node, ll &idx)
{
    vis[node]=1;
    euler[idx++]=node;

    for(auto &it:adj[node])
    {
        if(!vis[it])
        {
            getEulerTour(it, idx);
            euler[idx++]=node;
        }
    }



}

void EulerTour(ll root, ll n)
{
    ll idx = 0;

    getEulerTour(root, idx);

    f(i, 0, (2*n-1))
    {
        cout<<euler[i]<<" ";
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

    ll n = 4;

    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(2, 4);


    EulerTour(1, n);

    return 0;
}
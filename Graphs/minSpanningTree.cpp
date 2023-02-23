// 1. Sort all the edges acc. to the edge wt.
// 2. u and v can connect and be part of MST if parent(u)!=parent(v)
// 3. Do the union

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

class DSU {

private:
    vi parent, size;

public:
    DSU(ll n)
    {
        //starting from 0 to n. consider n also.
        f(i, 0, n + 1)
        {
            parent.pb(i);
            size.pb(1);
        }
    }


    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        else parent[node] = findParent(parent[node]);
    }

    void union(ll u, ll v)
    {
        ll pu = findParent(u);
        ll pv = findParent(v);

        if (pu == pv)
        {
            return ;
        }

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class node {
    ll u, v, wt;

    node(ll _u, ll _v, ll _wt)
    {
        u = _u;
        v = _v;
        wt = _wt;
    }
};

bool cmp(node a, node b)
{
    return a.wt < b.wt;
}

void kruksal(ll n, vector<node>&edges)
{
    sort(all(edges), cmp);

    DSU dsu(n);
    ll cost=0;
    vi mst;
    for(auto &it:edges)
    {
        ll u=it.u;
        ll v=it.v;
        ll wt=it.wt;

        if(dsu.findParent(u)!=dsu.findParent(v))
        {
            mst.pb(it);
            dsu.union(u,v);
            cost+=wt;
        }

    }
    deb(cost);
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
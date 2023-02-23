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
    vector<int> parent, size;

public:
    DSU(int n)
    {
        //starting from 0 to n. consider n also.
        for (int i = 0; i <= n ; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }


    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void Union(int  u, int  v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

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


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    DSU obj(5);




    return 0;
}
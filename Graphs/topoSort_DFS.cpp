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

void topoSortHelper(ll node, stack<int>&st)
{
    vis[node] = 1;
    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            //push other node first till we get node with no child
            topoSortHelper(i, st);
        }
    }
    // at last, curr node is pushed
    st.push(node);
}

void topoSort()
{
    stack<int>st;
    f(i, 1, n + 1)
    {
        if (!vis[i])
        {
            topoSortHelper(i, st);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
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

    return 0;
}
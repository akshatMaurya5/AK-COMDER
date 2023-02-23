#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << "=" << x <<'\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

vector<int>clr(10005,-1);
//let the two colors be 0 and 1;

bool checkBipartiteDFS(int node, int color)
{
    clr[node]=color;

    for(auto &i:adj[node])
    {
        if(clr[it]==-1)
        {
            //if unvisited
            if(checkBipartite(it,!color))
            {
                return true;
            }
        }
        else if(col[it]==color)
        {
            return true;
        }
    }
    return false;
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
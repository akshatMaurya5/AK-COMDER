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


void zero_one_bfs(ll source)
{
    vi dis(n,0);
    f(i,0,n)
    {
        dis[i]=INT_MAX;
    }
    deque<pii>dq;
    dis[source]=0;
    dq.push_back({source,0});

    while(!dq.empty())
    {
        ll node=dq.front().first;
        ll dist=dq.front().second;
        dq.pop_front();
        for(auto &it:adj[node])
        {
            int adjNode=it.first;
            int wt=it.second;

            if(dist+wt<dis[node])
            {
                dis[adjNode]=dist+wt;

                if(wt==1){
                    dq.push_back({adjNode,dist+wt});
                }
                else if(wt==0){
                    dq.push_front({adjNode,dist+wt});
                }
            }

        }

    }

    for(auto &it:dis)
    {
        cout<<it<<" ";
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
    // cout<<"akshat maurya";
       
    return 0;
}               

//ANOTHER CODE IS PASTED BELOW

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
void djkastra() {
    vi dis(n, 0);
    f(i, 0, n) {
        dis[i] = INT_MAX;
    }
    priority_queue<pii, vector<pii>, greater<pii>()>pq;
    dis[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        ll node = pq.front().first;
        ll dist = pq.front().second;
        pq.pop();
        for (auto &it : adj[node]) {
            int adjNode = it.first;
            int wt = it.second;

            if (dist + wt < dis[node]) {
                dis[adjNode] = dist + wt;
                pq.push_front({adjNode, dist + wt});

            }

        }

    }

    for (auto &it : dis)
    {
        cout << it << " ";
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



#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 5, m = 6, source = 1;
    vector<pair<int, int> > g[n + 1]; // assuming 1 based indexing of graph
    // Constructing the graph
    g[1].push_back({2, 2});
    g[1].push_back({4, 1});
    g[2].push_back({1, 2});
    g[2].push_back({5, 5});
    g[2].push_back({3, 4});
    g[3].push_back({2, 4});
    g[3].push_back({4, 3});
    g[3].push_back({5, 1});
    g[4].push_back({1, 1});
    g[4].push_back({3, 3});
    g[5].push_back({2, 5});
    g[5].push_back({3, 1});
    // Dijkstra's algorithm begins from here

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
    vector<int> distTo(n + 1, INT_MAX); //1-indexed array for calculating shortest paths

    distTo[source] = 0;
    pq.push(make_pair(0, source));  // (dist,source)

    while ( !pq.empty() )
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        vector<pair<int, int> >::iterator it;
        for ( it = g[prev].begin() ; it != g[prev].end() ; it++) {
            int next = it->first;
            int nextDist = it->second;
            if ( distTo[next] > distTo[prev] + nextDist) {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
    cout << "The distances from source " << source << " are : \n";
    for (int i = 1 ; i <= n ; i++) cout << distTo[i] << " ";
    cout << "\n";
    return 0;
}
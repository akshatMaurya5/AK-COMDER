void dijkstra()
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;

    vector<ll>dist(n + 1, 1e18);

    ll src = 1;
    dist[src] = 0;
    pq.push({0, src});
    vector<ll> parent(n + 1, -1);
    parent[src] = src;

    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        ll wt = x.first, node = x.second;


        for (auto &it : adj[node])
        {
            if (dist[it.first] > wt + it.second)
            {
                dist[it.first] = wt + it.second;
                pq.push({dist[it.first], it.first});
                parent[it.first] = node;
            }
        }
    }


    ll node = n;


    if (dist[node] == 1e18)
    {
        // cout << -1 << endl;
        return ;
    }


    vector<ll>path;
    path.pb(n);

    while (parent[node] != node)
    {
        path.pb(parent[node]);
        node = parent[node];
    }

    reverse(all(path));
}
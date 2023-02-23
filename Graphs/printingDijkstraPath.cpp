#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> shortestPath(int n, int m, vector<vector<int>>& edges)
	{
		vector<pair<int, int>>adj[n + 1];

		for (auto &it : edges)
		{
			int u = it[0],  v = it[1], wt = it[2];
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}

		vector<int>dist(n + 1, 1e9);
		vector<int>parent(n + 1);
		iota(parent.begin(), parent.end(), 0);

		dist[1] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;


		pq.push({0, 1});

		while (!pq.empty())
		{
			auto x = pq.top();
			pq.pop();
			int wt = x.first;
			int node = x.second;

			for (auto &it : adj[node])
			{
				int newNode = it.first;
				int newWt = it.second;

				if (wt + newWt < dist[newNode])
				{
					dist[newNode] = wt + newWt;

					parent[newNode] = node;

					pq.push({dist[newNode], newNode});

				}

			}

		}

		if (dist[n] == 1e9) return { -1};
		vector<int>path;

		int node = n;

		while (parent[node] != node)
		{
			path.push_back(node);
			node = parent[node];
		}

		path.push_back(1);

		reverse(path.begin(), path.end());

		return path;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	return 0;
}
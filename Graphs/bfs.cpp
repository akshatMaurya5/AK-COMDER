void topoSortHelper(int node, vector<int>adj[], vector<int>&vis, stack<int>&st)
{
	vis[node] = 1;

	for (auto &it : adj[node])
	{
		if (!vis[it])
		{
			topoSortHelper(it, adj, vis, st);
		}
	}
	st.push(node);
}

vector<int> topoSort(int n, vector<int> adj[])
{


	vector<int>ans;

	vector<int>indegree(n, 0);

	for (int i = 0; i < n; i++)
	{
		for (auto &it : adj[i])
		{
			indegree[it]++;
		}
	}

	for (auto &it : indegree) {
		cout << it << " ";
	}

	queue<int>q;

	for (auto &it : indegree) {
		if (it == 0) {
			q.push(it);
		}
	}

	while (!q.empty())
	{

		int node = q.front();
		ans.push_back(node);
		q.pop();
		for (auto &it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0) {
				q.push(it);
			}
		}
	}


	return ans;



}
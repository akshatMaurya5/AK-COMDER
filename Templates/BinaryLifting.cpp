class BinaryLifting
{
public:
    vector<vector<int>> parents;
    int n;
    vector<int> depth;
    BinaryLifting(int root, int n, vector<vector<int>> &adj)
    {
        this->n = n;
        depth.resize(n, 0);
        parents.resize(log2(n) + 1, vector<int>(n, -1));
        fillParents(root, adj);
    }

    void printDepth()
    {
        // deb(depth);
    }

    void fillParents(int root, vector<vector<int>> &adj)
    {
        // marking first parents
        dfs(root, -1, adj, parents[0]);

        // marking other parents

        for (int k = 1; k <= log2(n); k++)
        {
            for (int i = 0; i < n; i++)
            {
                int intermediate = parents[k - 1][i];

                if (intermediate != -1)
                {
                    parents[k][i] = parents[k - 1][intermediate];
                }
            }
        }
    }

    void dfs(int node, int par, vector<vector<int>> &adj, vector<int> &firstParent)
    {
        firstParent[node] = par;

        for (auto &it : adj[node])
        {
            if (par != it)
            {
                depth[it] = depth[node] + 1;
                dfs(it, node, adj, firstParent);
            }
        }
    }

    int kthParent(int node, int k)
    {
        int ans = -1;
        int n = parents[0].size();

        for (int i = 0; i <= log2(n); i++)
        {
            if (k & (1 << i)) // Kth bit set?
            {
                node = parents[i][node];

                if (node == -1)
                {
                    break;
                }
            }
        }
        return node;
    }

    int lca(int a, int b)
    {   // O(logn)

        if (depth[a] < depth[b])
        {
            swap(a, b);
        }

        int diff = depth[a] - depth[b];
        a = kthParent(a, diff);

        if (a == b)
            return a;

        // same as finding the last false in binary search
        for (int k = log2(n); k >= 0; k--)
        {
            int parA = parents[k][a];
            int parB = parents[k][b];

            if (parA != parB)
            {
                a = parA;
                b = parB;
            }
        }

        return parents[0][a];
    }

    int lca_brute(int a, int b)
    {
        // deb(a, b);
        // make 'a' as deepest node
        if (depth[a] < depth[b])
        {
            swap(a, b);
        }

        while (depth[a] > depth[b])
        {
            a = parents[0][a];
        }

        while (a != b)
        {
            a = parents[0][a];
            b = parents[0][b];
        }

        return a;
    }
};
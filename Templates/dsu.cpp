
class DSU {
private:
    vector<int> parent, size;
    int components;
    int n;
public:
    DSU(int n)
    {
        this->n = n;
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

    void unite(int  u, int  v)
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
        components--;
    }

};

//queries done 0-based
class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    int merge(int leftValue, int rightValue) {
        return leftValue + rightValue;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftNode = 2 * node + 1;
            int rightNode = 2 * node + 2;
            build(leftNode, start, mid);
            build(rightNode, mid + 1, end);
            tree[node] = merge(tree[leftNode], tree[rightNode]);
        }
    }

public:
    SegmentTree(vector<int>& input) {
        arr = input;
        n = input.size();
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return 0;
        }
        if (l <= start && r >= end) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        int leftSum = query(leftNode, start, mid, l, r);
        int rightSum = query(rightNode, mid + 1, end, l, r);

        return merge(leftSum, rightSum);
    }

    void update(int node, int start, int end, int idx, int newVal) {
        if (start == end) {
            arr[idx] = newVal;
            tree[node] = newVal;
        } else {
            int mid = (start + end) / 2;
            int leftNode = 2 * node + 1;
            int rightNode = 2 * node + 2;

            if (idx <= mid) {
                update(leftNode, start, mid, idx, newVal);
            } else {
                update(rightNode, mid + 1, end, idx, newVal);
            }

            tree[node] = merge(tree[leftNode], tree[rightNode]);
        }
    }

    int queryRange(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void updateIndex(int idx, int newVal) {
        update(0, 0, n - 1, idx, newVal);
    }
};
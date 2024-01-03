
//queries done 0-based
class SegmentTree {
private:
	vector<long long> tree;
	vector<long long> arr;
	long long n;

	long long merge(long long leftValue, long long rightValue) {
		return leftValue + rightValue;
	}

	void build(long long node, long long start, long long end) {
		if (start == end) {
			tree[node] = arr[start];
		} else {
			long long mid = (start + end) / 2;
			long long leftNode = 2 * node + 1;
			long long rightNode = 2 * node + 2;
			build(leftNode, start, mid);
			build(rightNode, mid + 1, end);
			tree[node] = merge(tree[leftNode], tree[rightNode]);
		}
	}

public:
	SegmentTree(vector<long long>& input) {
		arr = input;
		n = input.size();
		tree.resize(4 * n, 0);
		build(0, 0, n - 1);
	}

	long long query(long long node, long long start, long long end, long long l, long long r) {
		if (r < start || l > end) {
			return 0;
		}
		if (l <= start && r >= end) {
			return tree[node];
		}

		long long mid = (start + end) / 2;
		long long leftNode = 2 * node + 1;
		long long rightNode = 2 * node + 2;
		long long leftSum = query(leftNode, start, mid, l, r);
		long long rightSum = query(rightNode, mid + 1, end, l, r);

		return merge(leftSum, rightSum);
	}

	void update(long long node, long long start, long long end, long long idx, long long newVal) {
		if (start == end) {
			arr[idx] = newVal;
			tree[node] = newVal;
		} else {
			long long mid = (start + end) / 2;
			long long leftNode = 2 * node + 1;
			long long rightNode = 2 * node + 2;

			if (idx <= mid) {
				update(leftNode, start, mid, idx, newVal);
			} else {
				update(rightNode, mid + 1, end, idx, newVal);
			}

			tree[node] = merge(tree[leftNode], tree[rightNode]);
		}
	}

	long long make_query(long long l, long long r) {
		return query(0, 0, n - 1, l, r);
	}

	void make_update(long long idx, long long newVal) {
		update(0, 0, n - 1, idx, newVal);
	}
};
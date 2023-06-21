vector<int>segTree;

void build(vector<int>&arr, int start, int end, int index) { // O(n)

	if (start == end) { // leaf node
		segTree[index] = arr[start];
		return ;
	}

	int mid = (start + end) >> 1;

	//1-based indexing
	int left = 2 * index;
	int right = 2 * index + 1;

	build(arr, start, mid, left);
	build(arr, mid + 1, end, right);

	segTree[index] = segTree[left] + segTree[right];
}

void update(vector<int>&arr, int start, int end, int index, int pos, int value) { //O(nlogn)

	if (start == end) {
		arr[pos] = value;
		segTree[index] = value;
		return ;
	}

	int mid = (start + end) / 2;

	if (mid >= pos)
	{
		update(arr, start, mid, 2 * index, pos, value);
	}
	else {
		update(arr, mid + 1, end, 2 * index + 1, pos, value);
	}

	segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
}

int query(int start, int end, int index, int l, int r) { //O(logn)
	//gives sum from L to R

	//complete overlap
	if (start >= l && end <= r) {
		return segTree[index];
	}

	//disjoint
	if (l > end || r < start) {
		return 0;
	}

	//partial overlap

	int mid = (start + end) >> 1;

	int leftAns = query(start, mid, 2 * index, l, r);
	int rightAns = query(mid + 1, end, 2 * index + 1, l, r);

	return leftAns + rightAns;

}


void solve()
{
	int n;
	cin >> n;

	segTree.resize(4 * n + 1);

	vector<int>v(n);
	cin >> v;

	build(v, 0, n - 1, 1);

	deb(segTree);

	cout << query(0, n - 1, 1, 0 , 2) << endl;

	update(v, 0, n - 1, 1, 1 , 3);
	cout << query(0, n - 1, 1, 0 , 2) << endl;

	// cout << query(v, 0, n - 1, 1, 0, 2);
	// deb(segTree);


}

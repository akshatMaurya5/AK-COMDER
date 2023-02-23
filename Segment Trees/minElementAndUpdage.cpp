//CODE WORKING IN PROG.CPP

#include <bits/stdc++.h>
using namespace std;
class segTree {
	vector<int>seg;
public:

	segTree(int n) {
		seg.resize(4 * n);
	}

	void printSeg()
	{
		for (auto &it : seg)
		{
			cout << it << " ";
		}
	}
	void build(int idx, int lo, int hi, vector<int>&arr)
	{
		if (lo == hi) {
			seg[idx] = arr[lo];
			return ;
		}

		int mid = (lo + hi) >> 1;

		build(2 * idx + 1, lo, mid, arr);
		build(2 * idx + 2, mid + 1, hi, arr);

		seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
	}

	int query(int idx, int lo, int hi, int l, int r)
	{
		// no overlap
		if (r < lo || hi < l) return INT_MAX;

		//COMPLETE OVERLAP

		if (lo >= l  && hi <= r) return seg[idx];

		int mid = (hi + lo) >> 1;
		int left = query(2 * idx + 1, lo, mid, l, r);
		int right = query(2 * idx + 2, mid + 1, hi, l, r);

		return seg[idx] = min(left, right);
	}

	void update(int idx, int lo, int hi, int i, int val)
	{
		if (lo == hi)
		{
			seg[idx] = val;
			return ;
		}

		int mid = (lo + hi) >> 1;

		if (i <= mid) {
			update(2 * idx + 1, lo, mid, i, val);
		}
		else {
			update(2 * idx + 2, mid + 1, hi, i, val);
		}

		seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
	}


};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>arr = {6, 8, -1, 2, 17, 1, 3, 2, 4};
	int n = arr.size();

	segTree st(n);

	st.build(0, 0, n - 1, arr);

	// input test cases
	// 1
	// 2 6
	// 2
	// 7 - 5
	// - 1
	while (true)
	{
		int type;
		cin >> type;

		if (type == -1) {
			break;
		}

		if (type == 1) { //query
			int l, r;
			cin >> l >> r;

			int ans = st.query(0, 0, n - 1, l, r);
			cout << ans << endl;
		}
		else if (type == 2) { //update
			int idx, val;
			cin >> idx >> val;

			st.update(0, 0, n - 1, idx, val);

			// just for checking

			cout << st.query(0, 0, n - 1, 0, n - 1) << endl;
		}


	}

	return 0;
}


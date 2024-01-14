
//https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A


#include <bits/stdc++.h>
using namespace std;
#define ll long long

class node {
public:
	ll maxi, sum, suff, pref;

	node(ll val)
	{
		sum = val;
		suff = pref = maxi =  max(0LL, val);
	}
};

class SEG {
public:

	vector<node> seg;
	vector<ll> arr;
	ll n;

	SEG(ll n, vector<ll>& v) {
		this->n = n;
		seg.resize(4 * n + 1, node(0));
		arr = v;
		build(0, 0, n - 1);
	}

	node merge(node l, node r)
	{
		node ans(0);

		ans.maxi = max({l.maxi, r.maxi, l.suff + r.pref});
		ans.sum = l.sum + r.sum;
		ans.pref = max(l.pref, l.sum + r.pref);
		ans.suff = max(r.suff, l.suff + r.sum);
		return ans;
	}

	void build(ll idx, ll lo, ll hi)
	{
		if (lo == hi) {
			seg[idx] = node(arr[lo]);
			return ;
		}

		ll mid = (lo + hi) >> 1;

		build(2 * idx + 1, lo, mid);
		build(2 * idx + 2, mid + 1, hi);

		seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
	}

	// void printt()
	// {
	// cout << seg[0].maxi << " " << seg[1].maxi << endl;
	// }

	void update(ll idx, ll lo, ll hi, ll i, ll val)
	{
		if (lo == hi)
		{
			seg[idx] = node(val);
			return;
		}

		ll mid = (lo + hi) / 2;

		if (i <= mid)
			update(2 * idx + 1, lo, mid, i, val);
		else
			update(2 * idx + 2, mid + 1, hi, i, val);

		seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
	}

	void make_update(ll idx, ll val)
	{
		update(0, 0, n - 1, idx, val);
	}

	ll make_query()
	{
		auto ans = seg[0].maxi;
		return ans;
	}
};

void solve()
{
	ll n, q;
	cin >> n >> q;

	vector<ll> v(n);
	for (auto &it : v) cin >> it;

	SEG seg(n, v);


	cout << seg.make_query() << endl;

	while (q--) {

		ll idx, val;
		cin >> idx >> val;

		seg.make_update(idx, val);

		cout << seg.make_query() << endl;

	}


}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
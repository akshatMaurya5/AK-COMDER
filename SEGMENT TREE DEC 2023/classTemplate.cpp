class SEG {
public:
	vi seg;
	vi arr;
	ll n;

	SEG(ll n, vi &v) {
		this->n = n;
		seg.resize(4 * n + 1);
		arr = v;
		build(0, 0, n - 1);
	}

	void build(ll idx, ll lo, ll hi)
	{
		if (lo == hi) {
			seg[idx] = arr[lo];
			return ;
		}

		ll mid = (lo + hi) >> 1;

		build(2 * idx + 1, lo, mid);
		build(2 * idx + 2, mid + 1, hi);

		seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
	}

	ll query(ll idx, ll lo, ll hi, ll l, ll r)
	{
		//no overlap [l..r] [lo..hi]    [lo..hi] [l...r]

		if (r < lo || hi < l) return inf;

		//complete overlap
		// [l...lo...hi...r]
		if (lo >= l && hi <= r) return seg[idx];

		ll mid = (lo + hi) >> 1;


		ll left = query(2 * idx + 1, lo, mid, l, r);
		ll right = query(2 * idx + 2, mid + 1, hi , l, r);

		return merge(left, right);
	}

	void update(ll idx, ll lo, ll hi, ll i, ll val)
	{
		if (lo == hi)
		{
			seg[idx] = val;
			return;
		}

		ll mid = (lo + hi) / 2;

		if (i <= mid) update(2 * idx + 1, lo, mid, i, val);
		else update(2 * idx + 2, mid + 1, hi, i, val);



		seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
	}

	ll merge(ll l, ll r)
	{
		return min(l, r);
	}

	void make_update(ll idx, ll val)
	{
		update(0, 0, n - 1, idx, val);
	}

	ll make_query(ll l, ll r)
	{
		auto ans = query(0, 0, n - 1, l, r);
		return ans;
	}
};

void solve()
{
	ll n;
	cin >> n;
	vi v(n);
	cin >> v;

	SEG seg(n, v);

	// build(0, 0, n - 1, v);

	ll q;
	cin >> q;
	// deb(seg);
	while (q--)
	{
		ll type;
		cin >> type;

		if (type == 1)
		{

			ll l, r;
			cin >> l >> r;

			cout << seg.query(0, 0, n - 1, l, r) << line;
		}
		else {
			ll i, val;
			cin >> i >> val;

			seg.update(0, 0, n - 1, i, val);
			v[i] = val;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	fio;
	//srand(time(NULL));

	ll t = 1;
	// cin >> t;

	deb(t);

	while (t--)
	{
		solve();
	}

	// cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

	return 0;
}

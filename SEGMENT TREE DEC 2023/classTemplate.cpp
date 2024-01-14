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

	ll merge(ll l, ll r)
	{
		return min(l, r);
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

	/*
		// if we want to find index
		ll query(ll idx, ll lo, ll hi, ll x)
		{
			if (lo == hi) {
				return lo;
			}

			ll mid = (lo + hi) >> 1;


			//This if condition can be changed.
			if (seg[2 * idx + 1] >= x) {
				return query(2 * idx + 1, lo, mid, x);
			}
			else
				return query(2 * idx + 2, mid + 1, hi, x);
		}
	*/

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


class node {
public:
	ll maxi, mini, minidx, maxidx;

	node(ll value, ll idx)
	{
		maxi = value, mini = value, minidx = idx, maxidx = idx;
	}

	node() {
		maxi = -inf, mini = inf, minidx = -1, maxidx = -1;
	}
};

class SEG {
public:

	vector<node> seg;
	vector<ll> arr;
	ll n;

	SEG(ll n, vector<ll>& v) {
		this->n = n;
		seg.resize(4 * n + 1, node());
		arr = v;
		build(0, 0, n - 1);
	}

	node merge(node l, node r)
	{
		node ans;

		ans.mini = min(l.mini, r.mini);
		ans.maxi = max(l.maxi, r.maxi);

		if (ans.mini == l.mini) ans.minidx = l.minidx;
		else ans.minidx = r.minidx;

		if (ans.maxi == l.maxi) ans.maxidx = l.maxidx;
		else ans.maxidx = r.maxidx;
		return ans;
	}

	void build(ll idx, ll lo, ll hi)
	{
		if (lo == hi) {
			seg[idx] = node(arr[lo], lo);
			return ;
		}

		ll mid = (lo + hi) >> 1;

		build(2 * idx + 1, lo, mid);
		build(2 * idx + 2, mid + 1, hi);

		seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
	}

	node query(ll idx, ll lo, ll hi, ll l, ll r) {

		if (r < lo || hi < l) return node();

		if (lo >= l && hi <= r) return seg[idx];

		ll mid = (lo + hi) >> 1;

		auto left = query(2 * idx + 1, lo, mid, l, r);
		auto right = query(2 * idx + 2, mid + 1, hi, l, r);

		return merge(left, right);

	}

	node make_query(ll l, ll r)
	{
		return query(0, 0, n - 1, l, r);
	}
};
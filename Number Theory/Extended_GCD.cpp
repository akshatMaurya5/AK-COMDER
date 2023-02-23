#include <bits/stdc++.h>
#include"debug.h"
using namespace std;
#define ll long long

ll extendedGcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;

	ll d = extendedGcd(b, a % b, x1, y1);

	x = y1;
	y = x1 - y1 * (a / b);

	return d;
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
	ll x = 0, y = 0;
	ll ans = extendedGcd(8, 5, x, y);
	deb(x, y);
	return 0;
}
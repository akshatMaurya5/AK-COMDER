#include <bits/stdc++.h>
using namespace std;
#define ll long long

//CALCULATE X^N

double binaryExp(int x, int n)
{

	double ans = 1.0;
	long nn = n;
	if (nn < 0)nn *= -1;

	while (nn)
	{
		if (nn & 1) { //odd power
			ans *= x;
			nn--;
		}
		else { //even power
			x = x * x;
			nn >>= 1;
		}
	}
	if (n < 0)ans = (double)(1.0) / double(ans);

	return ans;
}

//FROM CP ALGORITHM
//a^b
ll binaryExponentiation(ll a, ll b)
{
	a %= mod;
	ll ans = 1;

	while (b > 0)
	{
		if (b & 1) {
			ans = (ans * a) % mod;
		}
		b >>= 1;
		a = (a * a) % mod;
	}

	return ans;

}


const int mod = 1e9 + 7;

ll binaryExponentiationWithModulo(ll a, ll b)
{
	ll ans = 1;

	while (b > 0)
	{
		if (b & 1)
		{
			ans = (ans * 1ll * a) % mod;
			b--;
		}
		else {
			a = (a * 1ll * a) % mod;
			b /= 2;
		}
	}

	return ans;
}

ll recursive(ll a, ll b)
{
	if (b == 0) return 1;

	ll ans = recursive(a, b / 2);

	if (b % 2) {
		return ans * ans * a;
	}

	return ans * ans;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);
	// cout << binaryExp(2, 5);

	cout << binaryExponentiation(2, 5);

	return 0;
}
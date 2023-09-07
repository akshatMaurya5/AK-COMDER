#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
// #define deb(x) cout << #x << "=" << x <<'\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vvi;


const ll mod = 1e9 + 7;

const ll N_ = 300007;

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll expo(ll base, ll pow) {
    if (pow == 0) return 1;
    ll half = expo(base, pow / 2);
    if (pow % 2 == 0) return mul(half, half);
    return mul(half, mul(half, base));
}

ll modInv(ll x) {
    return expo(x, mod - 2);
}


ll get_hash(string &s)
{
    ll prime = 31;
    ll hash = 0;
    ll p = 1;

    for (auto &it : s)
    {
        hash = (hash + (it - 'a' + 1) * p) % mod;

        p = (p * prime) % mod;
    }
    return hash;
}

vi get_prefix_hash(string &s)
{
    ll prime = 31, hash = 0, p = 1;
    vi pref;
    for (auto &it : s)
    {
        ll x = it - 'a' + 1;
        hash = (hash + (x * p) % mod) % mod;
        p = (p * prime) % mod;
        pref.pb(hash);
    }
    return pref;
}


ll rangehash(vi &pref, ll l, ll r)
{
    ll ans = pref[r];

    if (l - 1 >= 0)
    {
        ans = (ans - pref[l - 1] + mod) % mod;
    }

    ans = (ans / pow(31, l));
    // we need to take modular inverse here;
    // ans = (ans * modInv(l)) % mod;
    return ans;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    string s = "cabfab";

    ll hash = get_hash(s);
    deb(hash);

    vi pref = get_prefix_hash(s);
    deb(pref);

    ll h1 = rangehash(pref, 1, 2);
    ll h2 = rangehash(pref, 4, 5);
    deb(h1, h2);

    return 0;
}

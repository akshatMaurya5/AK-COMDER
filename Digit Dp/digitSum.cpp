#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << "=" << x <<'\n'
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;



ll func(ll idx, ll flag, ll sum, vi &num)
{
    if (idx == num.size()) {
        return sum;
    }

    ll limit = num[idx];
    if (flag)
    {
        limit = 9;
    }

    ll cnt = 0;

    for (ll digit = 0; digit <= limit; digit++)
    {
        if (flag)
        {
            cnt += func(idx + 1, flag, sum + digit, num);
        }
        else if (flag == 0)
        {
            if (digit < num[idx])
            {
                cnt += func(idx + 1, 1, sum + digit, num);
            }
            else {
                cnt += func(idx + 1, 0, sum + digit, num);
            }
        }
    }
    return cnt;
}

vector<ll>digits(ll n)
{
    vector<ll>ans;

    while (n)
    {
        ans.pb(n % 10);
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void solve()
{
    ll a, b;
    cin >> a >> b;

    vector<ll>num = digits(a - 1);
    ll ansL = func(0, 0, 0, num);

    num = digits(b);
    ll ansR = func(0, 0, 0, num);

    cout << ansR - ansL << endl;

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
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }


    return 0;
}
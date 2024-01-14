#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    ll n, k;
    cin >> n >> k;

    vi v(n);
    cin >> v ;

    ll i = 0, j = 0, ans = 0;

    ll sum = 0;

    while (j < n)
    {
        sum += v[j];

        while (sum > k)
        {
            sum -= v[i];
            i++;
        }
        ans += (j - i + 1);
        j++;
    }

    cout << ans << line;


    //to find no. of subarrays with sum atleast K

    // ll total = ((n) * (n + 1)) / 2;

    // deb(total);
    // ll finalans = total - ans;
    // cout << finalans << line;



    return 0;
}
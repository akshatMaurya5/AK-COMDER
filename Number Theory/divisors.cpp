#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;

    ll cnt = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++; // i is the divisor
            cout << i << endl;
            if (i != n / i)
            {
                cnt++;// n/i is also a divisor
                cout << n / i << endl;
            }
        }
    }

    cout << "Total=" << cnt << endl;

    return 0;
}
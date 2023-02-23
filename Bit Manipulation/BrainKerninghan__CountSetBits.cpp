//Brain Kerninghan Algo
//use to find the no. of set bits
// tc is no.of set bits


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

    while (n)
    {
        n &= (n - 1);
        cnt++;
    }

    cout << cnt << endl;
    return 0;

}
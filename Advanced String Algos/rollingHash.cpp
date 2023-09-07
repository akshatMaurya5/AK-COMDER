/*
hash(s) = s[0]*prime^0+s[1]*prime^1+s[2]*prime^3

i.e ->
hash(s) = Σ (s[i]-'a'+1) * p^i mod m
        (i=0 to n)

we are doing 1 based indexing here so p starts from 1
*/



#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

ll rollingHash(string s)
{
    ll n = s.size();
    ll prime = 31;

    ll hash = 0;

    ll p = 1;


    for (ll i = 0; i < n; i++)
    {
        hash = (hash + ((s[i] - 'a' + 1) * p) % mod) % mod;
        p = (p * prime) % mod;
    }

    return hash;

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
    cout << rollingHash("a");
    return 0;
}
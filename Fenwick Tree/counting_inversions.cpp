// https://www.spoj.com/problems/INVCNT/

/*

we build fenwick tree on freq array

[ 3 1 2]
freq array = [1 1 1]

first 3 comes, update freq array/fenwick tree with -1 ==> [1 1 0]

now all the number less than 3 are it's inversions i.e 1 and 2

so for 3 the answer is 2
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class FenwickTree {
public:

     ll n;
     vector<ll>fen;

     FenwickTree(vector<ll>&v)
     {
          n = v.size();
          fen.resize(n + 1, 0);


          for (ll i = 0; i < n; i++) {
               update(i, v[i]);
          }
     }

     void update(ll idx, ll val) {
          ++idx;
          while (idx <= n) {
               fen[idx] += val ;
               idx += (idx & -idx);
          }
     }

     ll query(ll idx) {
          ++idx;
          ll res = 0;
          while (idx > 0)  {
               res += fen[idx];
               idx -= (idx & -idx);
          }
          return res;
     }

     ll make_query(ll l, ll r) {
          return query(r) - query(l - 1);
     }

};

void solve()
{
     ll n;
     cin >> n;
     vector<ll>v(n);
     ll maxi = INT_MIN;
     for (auto &it : v) {
          cin >> it;
          maxi = max(maxi, it);
     }

     vector<ll>freq(maxi + 1);

     for (auto &it : v) {
          freq[it]++;
     }


     FenwickTree fen(freq);

     ll ans = 0;


     for (ll i = 0; i < n; i++) {
          ll val = v[i];

          fen.update(val, -1);

          ans += fen.query(val - 1);
     }

     cout << ans << endl;
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
          solve();
     return 0;
}
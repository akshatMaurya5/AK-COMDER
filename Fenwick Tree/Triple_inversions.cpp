// https://www.spoj.com/problems/TRIPINV/

// ai > aj > ak with i < j < k


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>


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
     // ai > aj > ak with i < j < k




     ll n;
     cin >> n;
     vi v(n);
     for (auto &it : v) cin >> it;


     vi freqRight(n + 1, 0);
     vi freqLeft(n + 1, 0);

     for (auto &it : v) {
          freqRight[it]++;
     }

     FenwickTree right(freqRight);
     FenwickTree left(freqLeft);

     ll ans = 0;


     for (ll j = 0; j < n; j++)
     {
          ll it = v[j];

          //remove this value from right

          right.update(it, -1);
          freqRight[it]--;
          // in right I want all elements which are less than aj

          ll cntRight = right.query(it - 1);

          // in left i want ai>aj i.e in range [aj+1....maxi]
          //here max value is upto n

          ll cntLeft = left.make_query(it + 1, n);

          ans += (cntLeft * cntRight);


          freqLeft[it]++;
          left.update(it, 1);
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

     //srand(time(NULL));

     ll t = 1;
     // cin >> t;

     while (t--)
     {
          solve();
     }

     // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

     return 0;
}
//
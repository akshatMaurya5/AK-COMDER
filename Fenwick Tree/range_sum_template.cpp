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

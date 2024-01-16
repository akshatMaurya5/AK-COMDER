class FenwickTree2D {
public:

     ll n, m;
     vector<vector<ll>>fen;

     FenwickTree2D(vector<vector<ll>>&v)
     {
          n = v.size();
          m = v[0].size();
          fen.resize(n + 1, vector<ll>(m + 1, 0));


          for (ll i = 0; i < n; i++) {
               for (ll j = 0; j < m; j++) {
                    update(i, j, v[i][j]);
               }
          }
     }

     FenwickTree2D(ll N)
     {
          n = N + 1;
          m = N + 1;
          fen.resize(n + 1, vector<ll>(n + 1, 0));
     }

     FenwickTree2D (ll N, ll M) {
          n = N + 1;
          m = M + 1;
          fen.resize(n + 1, vector<ll>(n + 1, 0));

     }
     void update(ll r, ll c, ll val) {

          for (ll i = r + 1; i <= n; i += i & -i) {
               for (ll j = c + 1; j <= m; j += j & -j) {
                    fen[i][j] += val;
               }
          }

     }

     ll query(ll r, ll c) {
          ll sum = 0;

          for (ll i = r + 1; i > 0; i -= i & ~i) {
               for (ll j = c + 1; j > 0 ; j -= j & ~j) {
                    sum += fen[i][j];
               }
          }
          return sum;
     }

     ll make_query(ll r1, ll c1, ll r2, ll c2) {

          return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) + query(r1 - 1, c1 - 1);
     }

};
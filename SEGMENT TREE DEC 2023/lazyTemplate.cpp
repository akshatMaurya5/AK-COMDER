class LAZYSEG {
public:
     vi seg, lazy;
     vi arr;
     ll n;

     LAZYSEG(ll n, vi &v) {
          this->n = n;
          seg.resize(4 * n + 1);
          lazy.resize(4 * n + 1);
          arr = v;
          build(0, 0, n - 1);
     }

     ll merge(ll l, ll r)
     {
          return l + r;
     }

     void build(ll idx, ll lo, ll hi)
     {
          if (lo == hi) {
               seg[idx] = arr[lo];
               return ;
          }

          ll mid = (lo + hi) >> 1;

          build(2 * idx + 1, lo, mid);
          build(2 * idx + 2, mid + 1, hi);

          seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
     }

     void update(ll idx, ll lo, ll hi, ll l, ll r, ll val)
     {
          //update pending updates and propogate down

          if (lazy[idx] != 0) {
               seg[idx] += (hi - lo + 1) * val;

               if (lo != hi) { //means there are children down, so propogate the update down
                    lazy[2 * idx + 1] = lazy[idx];
                    lazy[2 * idx + 2] = lazy[idx];
               }

               lazy[idx] = 0;
          }

          //no overlap? we just return
          // [lo..hi.l.r] [l...r..lo....hi]

          if (hi < l || r < lo) {
               return;
          }

          //complete overlap [l..lo....hi...r]
          if (lo >= l && hi <= r) {
               seg[idx] += (hi - lo + 1) * (val);

               if (lo != hi) {
                    lazy[2 * idx + 1] += val;
                    lazy[2 * idx + 2] += val;
               }
               return ;
          }

          //partial overlap

          ll mid = (lo + hi) >> 1;

          update(2 * idx + 1, lo, mid, l, r, val);
          update(2 * idx + 2, mid + 1, hi, l, r, val);

          seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
     }

     ll query(ll idx, ll lo, ll hi, ll l, ll r)
     {
          //first check if there is any update pending.

          if (lazy[idx] != 0) {
               seg[idx] += (hi - lo + 1) * lazy[idx];

               if (lo != hi) { //means there are children down, so propogate the update down
                    lazy[2 * idx + 1] = lazy[idx];
                    lazy[2 * idx + 2] = lazy[idx];
               }

               lazy[idx] = 0;
          }

          //no overlap
          if (hi < l || r < lo) {
               return 0;
          }

          //no overlap [l..r] [lo..hi]    [lo..hi] [l...r]

          if (r < lo || hi < l) return inf;

          //complete overlap
          // [l...lo...hi...r]
          if (lo >= l && hi <= r) return seg[idx];

          ll mid = (lo + hi) >> 1;


          ll left = query(2 * idx + 1, lo, mid, l, r);
          ll right = query(2 * idx + 2, mid + 1, hi , l, r);

          return merge(left, right);

     }


     void make_update(ll l, ll r, ll val)
     {
          update(0, 0, n - 1, l, r, val);
     }

     ll make_query(ll l, ll r)
     {
          auto ans = query(0, 0, n - 1, l, r);
          return ans;
     }
};

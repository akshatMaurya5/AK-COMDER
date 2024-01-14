#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(a) a.begin(),a.end()
#define rsz(a, n) a.resize(n)
#define f(i, a, b) for (int i = a; i < b; i++)
#define ff(i, a, b) for (int i = a; i <= b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
//#define deb(x) cout << #x << "=" << x <<'\n'
#define ll long long
#define pb emplace_back
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
typedef pair<ll, ll> pii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umii;
typedef map<ll, ll> mii;
typedef vector<vi> vvi;
#define fi first
#define se second
#define line "\n"
#define sz(s) s.size()
#define bits(n) __builtin_popcount(n)
const ll mod = 1e9 + 7;

/****************************************DEBUG************************************************************************************************************************************************************/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
/*********************************************************************************************************************************************************************************************************/

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it; return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
void printarr(ll arr[], ll n) {f(i, 0, n) cout << arr[i] << " "; cout << "\n";}
template<typename T>
void printvec(vector<T>v) {ll n = v.size(); f(i, 0, n)cout << v[i] << " "; cout << "\n";}
template<typename T>

ll getSum(vector<T>v) {ll n = v.size(); ll s = 0; f(i, 0, n)s += v[i]; return s;}
string decToBinary(int n) {string s = ""; int i = 0; while (n > 0) {s = to_string(n % 2) + s; n = n / 2; i++;} return s;}
ll binaryToDecimal(string n) {string num = n; ll dec_value = 0; int base = 1; int len = num.length(); for (int i = len - 1; i >= 0; i--) {if (num[i] == '1')dec_value += base; base = base * 2;} return dec_value;}
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
vpii dir = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool isPrime(ll n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; return true;}
bool isPowerOfTwo(int n) {if (n == 0)return false; return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x) {if (x >= 0) {ll sr = sqrt(x); return (sr * sr == x);} return false;}
/*******************************************************************************************************************************************************************************************************/
//ORDERED SET
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//use as
// Tree<pii> st;
/*******************************************************************************************************************************************************************************************************/

class node {
public:
     int sum;
     node() {
          sum = 0;
     }


}
class SEG {
public:
     vi seg;
     vi arr;
     ll n;

     SEG(ll n, vi &v) {
          this->n = n;
          seg.resize(4 * n + 1);
          arr = v;
          build(0, 0, n - 1);
     }

     ll merge(ll l, ll r)
     {
          return min(l, r);
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

     ll query(ll idx, ll lo, ll hi, ll l, ll r)
     {
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

     /*
          // if we want to find index
          ll query(ll idx, ll lo, ll hi, ll x)
          {
               if (lo == hi) {
                    return lo;
               }

               ll mid = (lo + hi) >> 1;


               //This if condition can be changed.
               if (seg[2 * idx + 1] >= x) {
                    return query(2 * idx + 1, lo, mid, x);
               }
               else
                    return query(2 * idx + 2, mid + 1, hi, x);
          }
     */

     void update(ll idx, ll lo, ll hi, ll i, ll val)
     {
          if (lo == hi)
          {
               seg[idx] = val;
               return;
          }

          ll mid = (lo + hi) / 2;

          if (i <= mid) update(2 * idx + 1, lo, mid, i, val);
          else update(2 * idx + 2, mid + 1, hi, i, val);



          seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
     }

     void make_update(ll idx, ll val)
     {
          update(0, 0, n - 1, idx, val);
     }

     ll make_query(ll l, ll r)
     {
          auto ans = query(0, 0, n - 1, l, r);
          return ans;
     }
};


void solve()
{

}

int main()
{
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("error.txt", "w", stderr);
     freopen("output.txt", "w", stdout);
#endif

     fio;
     //srand(time(NULL));

     ll t = 1;
     cin >> t;

     while (t--)
     {
          solve();
     }

     // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

     return 0;
}

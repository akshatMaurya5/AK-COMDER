#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(a) a.begin(),a.end()
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
template<typename Node, typename Update>
struct LazySGT {
  vector<Node> tree;
  vector<bool> lazy;
  vector<Update> updates;
  vector<ll> arr; // type may change
  int n;
  int s;
  LazySGT(int a_len, vector<ll> &a) { // change if type updated
    arr = a;
    n = a_len;
    s = 1;
    while (s < 2 * n) {
      s = s << 1;
    }
    tree.resize(s); fill(all(tree), Node());
    lazy.resize(s); fill(all(lazy), false);
    updates.resize(s); fill(all(updates), Update());
    build(0, n - 1, 1);
  }
  void build(int start, int end, int index) { // Never change this
    if (start == end)   {
      tree[index] = Node(arr[start]);
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
  }
  void pushdown(int index, int start, int end) {
    if (lazy[index]) {
      int mid = (start + end) / 2;
      apply(2 * index, start, mid, updates[index]);
      apply(2 * index + 1, mid + 1, end, updates[index]);
      updates[index] = Update();
      lazy[index] = 0;
    }
  }
  void apply(int index, int start, int end, Update& u) {
    if (start != end) {
      lazy[index] = 1;
      updates[index].combine(u, start, end);
    }
    u.apply(tree[index], start, end);
  }
  void update(int start, int end, int index, int left, int right, Update& u) {  // Never Change this
    if (start > right || end < left)
      return;
    if (start >= left && end <= right) {
      apply(index, start, end, u);
      return;
    }
    pushdown(index, start, end);
    int mid = (start + end) / 2;
    update(start, mid, 2 * index, left, right, u);
    update(mid + 1, end, 2 * index + 1, left, right, u);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
  }
  Node query(int start, int end, int index, int left, int right) { // Never change this
    if (start > right || end < left)
      return Node();
    if (start >= left && end <= right) {
      pushdown(index, start, end);
      return tree[index];
    }
    pushdown(index, start, end);
    int mid = (start + end) / 2;
    Node l, r, ans;
    l = query(start, mid, 2 * index, left, right);
    r = query(mid + 1, end, 2 * index + 1, left, right);
    ans.merge(l, r);
    return ans;
  }
  void make_update(int left, int right, ll val) {  // pass in as many parameters as required
    Update new_update = Update(val); // may change
    update(0, n - 1, 1, left, right, new_update);
  }
  Node make_query(int left, int right) {
    return query(0, n - 1, 1, left, right);
  }
};

struct Node1 {
  ll val; // may change
  Node1() { // Identity element
    val = 0;    // may change

  }
  Node1(ll p1) {  // Actual Node
    val = p1; // may change
  }
  void merge(Node1 &l, Node1 &r) { // Merge two child nodes
    val = l.val + r.val;  // may change
  }
};

struct Update1 {
  ll val; // may change
  Update1() { // Identity update
    val = -1;
    //-1 siginifies most updated state
  }
  Update1(ll val1) { // Actual Update
    val = val1;
  }
  void apply(Node1 &a, int start, int end) { // apply update to given node
    if (val == -1) { //alrady in most updated state
      return ;
    }
    a.val = val * (end - start + 1); // may change
  }
  void combine(Update1& new_update, int start, int end) {
    val = new_update.val;
  }
};

//range sum
//update --> all values become x


void solve()
{
  ll n = 4;
  vi arr = {1, 2, 3, 4};

  LazySGT<Node1, Update1>seg = LazySGT<Node1, Update1>(n, arr);
  Node1 ans = seg.make_query(0, 3);

  cout << ans.val << line;
  seg.make_update(0, 3, 0);

  ans = seg.make_query(0, 3);

  cout << ans.val << line;


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

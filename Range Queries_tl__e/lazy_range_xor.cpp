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

vector<int>segtree, lazy;

//index is for segment tree, start, end and pos are for arr

int merge(int a, int b) {
    return a ^ b;
}

void build(vector<int>&arr, int start, int end, int index) { //O(n)
    if (start == end) {
        segtree[index] = arr[start];
        return;
    }

    int mid = (start + end) >> 1;
    int left = 2 * index, right = 2 * index + 1;

    build(arr, start, mid, left);
    build(arr, mid + 1, end, right);

    segtree[index] = merge(segtree[left],  segtree[right]);
}

//propogate downwards
void propogate(int start, int end, int index)
{
    if (start == end) { //leaf node
        lazy[index] = -1;
        return ;
    }

    lazy[2 * index] = lazy[index];
    lazy[2 * index + 1] = lazy[index];

    lazy[index] = -1;
}

void update(int start, int end, int index, int l, int r, int value) { //O(logn)

    if (lazy[index] != -1)
    {
        segtree[index] = ((end - start + 1) & 1) ? lazy[index] : 0;
        propogate(start, end, index);
    }

    //now my node is in most updated state

    if (start >= l && end <= r) { //complete overlap
        segtree[index] = ((end - start + 1) & 1) ? value : 0;
        lazy[index] += value;
        propogate(start, end, index);
        return ;
    }


    if (start > r || end < l) { //disjoint
        return ;
    }

    // partial overlap -- > update on both the sides



    int mid = (start + end) >> 1;

    update(start, mid, 2 * index, l, r, value);
    update(mid + 1, end, 2 * index + 1, l, r, value);

    segtree[index] = merge(segtree[2 * index], segtree[2 * index + 1]);

}

//query for range l to r
int query(int start, int end, int index, int l, int r) { //O(log n)


    if (lazy[index] != -1) {
        segtree[index] ((end - start + 1) & 1) ? lazy[index] : 0;
        propogate(start, end, index);
    }


    //complete overlap
    if (start >= l && end <= r) {
        return segtree[index];
    }

    //disjoint
    if (l > end || start > r) {
        return 0;
    }

    //partial overlap

    int mid = (start + end) >> 1;


    int leftAns = query(start, mid, 2 * index, l, r);
    int rightAns = query(mid + 1, end, 2 * index + 1, l, r);


    return merge(leftAns, rightAns);
}


// update range with making all values equal to X
// give range xor

void solve()
{
    int n;
    cin >> n;
    segtree.resize(4 * n);
    lazy.resize(4 * n, -1);
    vector<int>arr(n);
    cin >> arr;


    build(arr, 0, n - 1, 1);

    deb(arr);
    deb(segtree);
    deb(lazy);
    cout << query(0, n - 1, 1, 0, 2) << line;


    // //udpating val at range 0 to 0 adding 500
    update(0, n - 1, 1, 0, 0, 500);
    // deb(arr);
    // deb(segtree);
    cout << query(0, n - 1, 1, 0, 2) << line;

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
    // cin >> t;

    while (t--)
    {
        solve();
    }

    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

    return 0;
}

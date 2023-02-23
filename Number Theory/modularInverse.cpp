#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(a) a.begin(),a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define ff(i, a, b) for (int i = a; i <= b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define deb(x) cout << #x << "=" << x <<'\n'
#define ll long long
#define pb emplace_back
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
typedef pair<ll, ll> pii;
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
/*************************************************************************************************************************************************************/

ll binExp(ll a, ll b)
{
	a %= mod;
	ll ans = 1;

	while (b)
	{
		if (b & 1)
		{
			ans = (ans * a) % mod;
		}
		b >>= 1;

		a = (a * a) % mod;
	}
	return ans;
}

ll modInv(ll n, ll p)
{
	return binExp(n, mod - 2);
}


void solve()
{
	ll n;
	cin >> n;
	vi fact(n + 1);
	fact[0] = fact[1] = 1;

	ff(i, 2, n)
	{
		fact[i] = (fact[i - 1] * i) % mod;
	}

	ll total = fact[n];



}

int main() {
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	fio;
	//srand(time(NULL));
	solve();
	return 0;
}

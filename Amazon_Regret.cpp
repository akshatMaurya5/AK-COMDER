#include <bits/stdc++.h>
using namespace std;
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

vector<string>getWords(string s)
{
	// stringstream str(s);

	// string res;
	vector<string>ans;

	// while (str >> res)
	// {
	// 	ans.push_back(res);
	// }
	string word = "";
	int i = 0;
	while (i < s.size())
	{
		if (s[i] == ' ') {
			ans.push_back(word);
			word = "";
		}
		word += s[i];
		i++;
	}

	ans.push_back(word);

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<string>queries;
	queries.push_back("register david david123");
	queries.push_back("register adam adam1");
	queries.push_back("login david david123");
	queries.push_back("login adam adam2");
	queries.push_back("logout david");


	// deb(queries);

	map<string, string>user;
	set<string>login;

	for (auto &it : queries)
	{
		vector<string>curr = getWords(it);
		// deb(curr);
		string start = curr[0];

		if (start == "register")
		{
			string email = curr[1];
			string pass = curr[2];

			if (user.count(email))
			{
				cout << "Username already exists\n";
			}
			else {
				cout << "Registered succcessfully\n";
				user[email] = pass;
			}
			deb(user);
		}
		else if (start == "login")
		{
			string email = curr[1];
			string pass = curr[2];

			if (user.count(email))
			{
				if (user[email] == pass)
				{
					login.insert(email);
					cout << "Logged in succcessfully\n";
				}
				else {
					cout << "Login Unsucessful.\n";
				}
			}
			else {
				cout << "Login Unsucessful.\n";
			}

		}
		else if (start == "logout")
		{
			string email = curr[1];

			if (login.count(email))
			{
				login.erase(email);
				cout << "Logout succcessful.\n";
			}
			else {
				cout << "Logout Unsucessful.\n";
			}

		}
	}

	return 0;
}
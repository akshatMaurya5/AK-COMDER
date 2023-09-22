#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node*arr[26];
	bool flag = false;
};

class Trie {
private:
	Node*root;

public:

	Trie() {
		root = new Node();
	}

	void insert(string &s)
	{
		int n = s.size();

		Node*node = root;

		for (int i = 0; i < n; i++)
		{
			if (!node->arr[s[i] - 'a'])
			{
				node->arr[s[i] - 'a'] = new Node();
			}
			node = node->arr[s[i] - 'a'];
		}

		node->flag = true;
		// cout << "inserted" << endl;
	}


	bool searchPrefix(string &s)
	{
		int n = s.size();
		Node*node = root;

		for (int i = 0; i < n; i++)
		{
			if (!node->arr[s[i] - 'a'])
			{
				return false;
			}
			node = node->arr[s[i] - 'a'];
		}

		return true;
	}

	bool searchString(string &s)
	{
		int n = s.size();
		Node*node = root;

		for (int i = 0; i < n; i++)
		{
			if (!node->arr[s[i] - 'a'])
			{
				return false;
			}
			node = node->arr[s[i] - 'a'];
		}

		if (node->flag) {
			return true;
		}
		return false;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int q;
	cin >> q;

	Trie trie;

	// string s = "akshatgooglesde";
	// trie.insert(s);

	// string pref = "akshatgoogle";

	// cout << trie.searchPrefix(pref);

	while (q--)
	{
		int t;
		cin >> t;
		string s;
		cin >> s;

		if (t == 1)
		{
			trie.insert(s);
		}
		else if (t == 2)
		{
			cout << trie.searchString(s) << endl;

		}
		else {
			cout << trie.searchPrefix(s) << endl;
		}
	}
	return 0;
}
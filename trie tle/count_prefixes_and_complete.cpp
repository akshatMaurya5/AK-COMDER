#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node*arr[26];
	int prefix = 0, complete = 0;
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
			//doing after moving
			node->prefix++;

		}

		node->complete++;
	}

	void delString(string &s)
	{
		int n = s.size();

		Node*node = root;

		for (int i = 0; i < n; i++)
		{
			node = node->arr[s[i] - 'a'];

			node->prefix--;

		}

		node->complete--;
	}


	int searchPrefix(string &s)
	{
		int n = s.size();
		Node*node = root;

		for (int i = 0; i < n; i++)
		{
			if (!node->arr[s[i] - 'a'])
			{
				return 0;
			}
			node = node->arr[s[i] - 'a'];
		}

		return node->prefix;
	}

	int searchString(string &s)
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

		return node->complete;
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
		else if (t == 3) {
			cout << trie.searchPrefix(s) << endl;
		}
		else {
			trie.delString(s);
		}
	}
	return 0;
}